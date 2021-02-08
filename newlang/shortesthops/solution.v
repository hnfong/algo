import os

struct GlobalState {
    mut:
        bt map[int]int
        w map[int][]int
        pbuf []string
}

// This echo() basically functions as "print()". However, there seems to be a
// couple issues with println and print - - print() and println() seem to be
// using different buffers, when the output is not to a terminal the suspected
// buffering issue seems to sometimes cause out of order output.... - somehow
// just calling print() on a lot of small chunks of output is much slower than
// expected. To the point that this implementation is actually faster.
fn (mut g GlobalState) echo(s string) {
    g.pbuf << s
    if g.pbuf.len > 100 {
        print(g.pbuf.join(""))
        g.pbuf = []string{}
    }
}

fn (mut g GlobalState) flush() {
    print(g.pbuf.join(""))
    g.pbuf = []string{}
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

fn backtrack(mut g GlobalState, k int) {
    if g.bt[k] > 0 {
        backtrack(mut g, g.bt[k])
        g.echo(' ${k}')
    } else {
        g.echo('${k}')
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
            backtrack(mut g, i)
            g.echo('\n')
        } else {
            g.echo('0\n')
        }
    }

    g.flush()
}

