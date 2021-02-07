import os

fn main() {
    mut w := []int{}
    for s:=os.get_line(); s != ''; s=os.get_line() {
        w << s.int()
    }

    for i in 0..w.len {
        for j:=i; j>0; j-- {
            if w[j-1] > w[j] {
                t := w[j]
                w[j] = w[j-1]
                w[j-1] = t
            }
        }
    }

    for v in w { println(v) }
}

