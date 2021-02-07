#!/usr/bin/env python3

import datetime
import glob
import os
import subprocess
import sys

LOG_level = ["DEBUG", "INFO", "WARNING", "ERROR"]
LOG_default = 0

def LOG(s, lvl=1):
    if (lvl >= LOG_default):
        print(f'{datetime.datetime.now()} {LOG_level[lvl]} {s}')

def DEBUG(s):
    LOG(s, 0)

def WARN(s):
    LOG(s, 1)

def ERROR(s):
    LOG(s, 2)

def run_test_case(args, input_file, output_file):
    with open(input_file, 'rb') as input_stream:
        DEBUG(f'Running test case: {args} {input_file} {output_file}')
        p = subprocess.Popen(args, shell=False, stdin=input_stream, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = p.communicate()
        # Might want to stream the output later? But we probably don't expect
        # interactive outputs and the outputs should be pretty small
        if stderr:
            WARN("stderr not empty! " + stderr)
        if p.returncode != 0:
            ERROR("program exited with non-zero code: %d" % p.returncode)
            return False
        return stdout.strip() == open(output_file, "rb").read().strip()

def check_with_cmd(lang, args, problem, tcglob):
    if tcglob is not None:
        inputs = glob.glob(problem + os.sep + tcglob)
    else:
        inputs = glob.glob(problem + os.sep + "input[0-9]*.txt")

    outputs = [fn.replace('input', 'output') for fn in inputs]

    overall = True
    for fi, fo in zip(inputs, outputs):
        result = run_test_case(args, fi, fo)
        DEBUG(f'Lang={lang} Problem={problem} TestCase={fi} Result={result}')
        overall = overall and result

    return overall

def compile_with_cmd(lang, args):
    p = subprocess.Popen(args, shell=False)
    p.communicate()

    if p.returncode != 0:
        ERROR(f"Compile command returned non-zero exit code: {args}")
        return False

    return True

def check_for_lang(lang, problem, tcglob=None):
    if lang == 'ALL':
        q = True
        for ll in ('c', 'cpp', 'py', 'unix', 'v'):
            src = os.path.sep.join([problem, "solution." + ll])
            if os.path.exists(src):
                q = q and check_for_lang(ll, problem, tcglob)
        return q

    # TODO: modularize this later
    src = os.path.sep.join([problem, "solution." + lang])
    binary = os.path.sep.join([problem, "solution." + lang + ".exe"])

    if lang in ('unix', 'py'):
        # Bash script does not need compilation
        result = compile_with_cmd(lang, ['cp', src, binary])
        result = compile_with_cmd(lang, ['chmod', '0755', binary])
        result = check_with_cmd(lang, [binary, ], problem, tcglob)
    elif lang == 'cpp':
        result = compile_with_cmd(lang, ['clang++', '-std=c++17', '-o', binary, src])
        result = result and check_with_cmd(lang, [binary, ], problem, tcglob)
    elif lang == 'c':
        result = compile_with_cmd(lang, ['clang', '-o', binary, src])
        result = result and check_with_cmd(lang, [binary, ], problem, tcglob)
    elif lang == 'v':
        result = compile_with_cmd(lang, ['v', '-o', binary, src])
        result = result and check_with_cmd(lang, [binary, ], problem, tcglob)
    else:
        raise ValueError("Unsupported language: %s" % lang)

    LOG(f'Lang={lang} Problem={problem} OverallResult={result}')
    return result


def main(args):
    if len(args) == 3:
        LOG(f"Language={args[1]} Problem={args[2]}")
        result = check_for_lang(args[1], args[2])
    elif len(args) > 3:
        LOG(f"Language={args[1]} Problem={args[2]} Cases={args[3]}")
        result = check_for_lang(args[1], args[2], args[3])
    else:
        LOG(f'Usage: {args[0]} lang problem [testcase-rattern]')

    sys.exit(0 if result else 1)

if __name__ == "__main__":
    main(sys.argv)
