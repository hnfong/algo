import os

struct GlobalState {
    mut:
        bt map[int]int
        w map[int][]int
}

struct Edge {
    to int
    from int
}

// FIXME: can't get templating to work :(
struct Queue {
    mut:
        data []Edge
        sidx int
}

fn (mut q Queue) len() int {
    return q.data.len - q.sidx
}

fn (mut q Queue) push(k Edge) {
    q.data << k
}

fn (mut q Queue) pop() Edge {
    res := q.data[q.sidx]
    q.sidx++
    return res
}

fn backtrack(g &GlobalState, k int) {
    if g.bt[k] > 0 {
        backtrack(g, g.bt[k])
        print(' ${k}')
    } else {
        print('${k}')
    }
}

fn main() {
    mut g := GlobalState{}

    n := os.get_line().int()

    for s := os.get_line(); s != ''; s = os.get_line() {
        splitter := s.split(' ')
        a := splitter[0].int()
        b := splitter[1].int()

        g.w[a] << b
    }

    for i := 1; i <= n; i++ {
        g.w[i].sort()
    }

    mut q := Queue{}

    q.push(Edge{1, -1})

    for q.len() != 0 {
        e := q.pop()

        if g.bt[e.to] == 0 {
            g.bt[e.to] = e.from
        } else {
            continue
        }

        for k in g.w[e.to] {
            q.push(Edge{k, e.to})
        }
    }

    for i := 2; i <= n; i++ {
        if g.bt[i] > 0 {
            // FIXME: output seems slow, maybe I should implement a stringbuffer myself? @_@
            backtrack(g, i)
            print('\n')  // as of writing println and print seems to be using different buffers...
        } else {
            print('0\n')
        }
    }
}

