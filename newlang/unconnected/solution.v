import os

struct GlobalState {
  mut:
    w map[int][]int
    v map[int]bool
}

fn visit(mut g &GlobalState, k int) {
    if g.v[k] { return }
    g.v[k] = true

    for d in g.w[k] {
        visit(mut g, d)
    }
}

fn main() {
    n := os.get_line().int()

    mut g := &GlobalState{}

    for s := os.get_line(); s != ''; s = os.get_line() {
        splitter := s.split(" ")
        a := splitter[0].int()
        b := splitter[1].int()
        g.w[a] << b
    }

    visit(mut g, 1)

    for i in 1..n+1 {
        if !g.v[i] {
            println(i)
        }
    }
}
