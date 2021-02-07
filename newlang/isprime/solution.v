import math
import os

fn isprime(k int) bool {
    sr := int(math.sqrt(k+1))
    for i in 2..sr+1 {
        if k % i == 0 {
            return false
        }
    }

    return true
}

fn main() {
    for {
        s := os.get_line()
        if s == '' {
            break
        }
        if isprime(s.int()) {
            println('PRIME')
        } else {
            println('NOT PRIME')
        }
    }
}
