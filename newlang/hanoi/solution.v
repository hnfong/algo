import os

fn hanoi(n int, fr string, to string, tm string) {
    if n == 0 {
        return
    }
    hanoi(n-1, fr, tm, to)
    println('${fr} ${to}')
    hanoi(n-1, tm, to, fr)
}

fn main() {
    k := os.get_line().int()
    hanoi(k, 'A', 'C', 'B')
}
