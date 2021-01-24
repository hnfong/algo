#!/usr/bin/env python3

import datetime
import glob
import os
import subprocess
import sys

LOG_level = ["DEBUG", "INFO", "WARNING", "ERROR"]
LOG_default = 1

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

def check_for_lang(lang, problem, tcglob=None):
    # TODO: modularize this later
    if lang == 'bash':
        # Bash script does not need compilation
        result = check_with_cmd(lang, [os.path.sep.join([problem, "solution.bash"]), ], problem, tcglob)
        LOG(f'Lang={lang} Problem={problem} OverallResult={result}')
        sys.exit(0 if result else 1)
    else:
        raise ValueError("Unsupported language: %s" % lang)

def main(args):
    if len(args) == 3:
        LOG(f"Language={args[1]} Problem={args[2]}")
        check_for_lang(args[1], args[2])
    elif len(args) > 3:
        LOG(f"Language={args[1]} Problem={args[2]} Cases={args[3]}")
        check_for_lang(args[1], args[2], args[3])
    else:
        LOG(f'Usage: {args[0]} lang problem [testcase-rattern]')

if __name__ == "__main__":
    main(sys.argv)
