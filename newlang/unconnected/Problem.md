# Unconnected

Given n vertices labelled 1..n, and a list of unidirectional edges a\_k, b\_k
that connects a\_k-\>b\_k, output the vertices that are not reachable from
vertex 1.

## Input specification

First line is an integer n. Second line onwards each have two integers a\_k and
b\_k, denoting an edge from vertex a\_k to b\_k. Input is terminated by EOF.

## Output specification

A (numerically) sorted list of unreachable vertices.

## Example input

6
4 5
1 2
2 4

## Example output

3
6
