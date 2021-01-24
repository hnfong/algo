#!/usr/bin/env python3

def move(N, fr, to, tmp):
    if N > 0:
        move(N - 1, fr, tmp, to)
        print(fr, to)
        move(N - 1, tmp, to, fr)

N = int(input())
move(N, 'A', 'C', 'B')
