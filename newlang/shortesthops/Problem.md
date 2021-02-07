# Shortest hops

Given n vertices labelled 1..n, and a list of unidirectional edges a\_k, b\_k
that connects a\_k-\>b\_k, output the shortest path from vertex 1 to all the
other vertices.

## Input specification

First line is an integer n. Second line onwards each have two integers a\_k and
b\_k, denoting an edge from vertex a\_k to b\_k. Input is terminated by EOF.

## Output specification

N-1 lines, the k-th line contains the shortest path from vertex 1 to vertex
k+1. If there are multiple such paths, output the smallest one lexigraphically.
If there is no path from vertex 1 to vertex k, output "0"

## Example input

6
4 5
1 2
2 4

## Example output

1 2
0
1 2 4
1 2 4 5
0
