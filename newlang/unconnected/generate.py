#!/usr/bin/env python3

"""
Usage: ./generate.py <n>  > inputX.txt
"""
import sys
import random
import math

args = list(sys.argv)

args.pop(0)

if args[0] == '-f':  # full graph
    args.pop(0)
    n = int(args[0])
    print(n)
    for i in range(0, n):
        for j in range(0,n):
            if i == j: continue
            print(f'{i+1} {j+1}')
elif args[0] == '-s': # chained
    args.pop(0)
    n = int(args[0])
    print(n)
    for i in range(0, n-1):
        print(f'{i+1} {i+2}')
else:
    already = set()
    n = int(args[0])
    print(n)
    k = random.randint(n//2, n) * int(math.log(random.randint(n//2, n), 3))
    for it in range(0, k):
        a = random.randint(0, n) + 1
        b = random.randint(0, n) + 1

        k = (a, b)
        if k not in already:
            already.add(k)
            print(f'{a} {b}')
