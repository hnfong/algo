# Tower of Hanoi

Solve the problem of the [Tower of
Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) with size `k`. Input will
be a single integer `k` < 10. Assuming there are 3 stacks in the system
(labelled A, B, C), and initially all the `k` discs are stacked on stack A. The
output should be the steps to move all the stacks from A to C, denoted by
`{FROM} {TO}`, meaning moving the top disc from `{FROM}` to `{TO}`.  The number
of steps must be optimal.

## Example input

```
3
```

## Example output

```
A C
A B
C B
A C
B A
B C
A C
```
