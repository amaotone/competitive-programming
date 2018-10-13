#![allow(dead_code, unused_imports, non_snake_case)]


use std::io::*;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::str::FromStr;
use std::iter::FromIterator;

const MOD: i32 = 1_000_000_007;


fn powmod(a: i64, p: i64, m: i64) -> i64 {
    let mut ret = 1i64;
    let mut aa = a;
    let mut pp = p;
    while pp >= 1 {
        if pp & 1 == 1 {
            ret *= aa;
            ret %= m;
        }
        aa = aa * aa % m;
        pp >>= 1;
    }
    ret
}

fn inv(a: i64, m: i64) -> i64 {
    powmod(a, m - 2, m)
}

struct Combination {
    fact: Vec<i64>,
    invfact: Vec<i64>,
    modulo: i64
}

impl Combination {
    fn new(n: usize, modulo: i64) -> Self {
        let mut fact: Vec<i64> = vec![0; n];
        let mut invfact: Vec<i64> = vec![0; n];
        fact[0] = 1;
        for i in 1..n {
            fact[i] = fact[i - 1] * i as i64 % modulo;
        }
        invfact[n - 1] = inv(fact[n - 1], modulo);
        for i in (0..n - 1).rev() {
            invfact[i] = (invfact[i + 1] * (i + 1) as i64) % modulo;
        }

        Combination { fact: fact, invfact: invfact, modulo: modulo }
    }

    fn combination(&self, n: usize, k: usize) -> i64 {
        if n < k {
            return 0;
        }
        self.fact[n] * self.invfact[n - k] % self.modulo * self.invfact[k] % self.modulo
    }
}

fn main() {
    let n: usize = input();
    let n = n + 1;
    let a: Vec<usize> = input();

    // 重複を探す
    let mut cnt = HashMap::new();
    for &x in &a {
        *cnt.entry(x).or_insert(0) += 1;
    }
    let mut cnt = Vec::from_iter(cnt);
    cnt.sort_by(|a, b| (&b).1.cmp(&a.1));

    let dup = cnt[0].0;
//    println!("{:?}", cnt);
//    println!("{}", dup);

    let mut l = n+1;
    let mut r = n+1;
    for i in 0..n {
        if a[i] == dup {
            if l == n+1 {
                l = i;
            } else {
                r = i;
            }
        }
    }
//    println!("{} {}", l, r);
    let comb = Combination::new(n+1, 1_000_000_007);
    for k in 1..n+1 {
        println!("{}", comb.combination(n, k)-comb.combination(l+n-r-1, k-1));
    }
}

trait Read {
    fn read(s: &str) -> Self;
}

fn input<T: Read>() -> T {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    T::read(buf.trim_right())
}

macro_rules! read_impl {
    ($($t:ty)*) => ($(
        impl Read for $t {
            fn read(s: &str) -> $t{
                s.parse().unwrap()
            }
        }
    )*)
}
read_impl! { usize u8 u16 u32 u64 isize i8 i16 i32 i64 f32 f64 }

impl Read for String {
    fn read(s: &str) -> Self {
        s.to_string()
    }
}

impl Read for Vec<char> {
    fn read(s: &str) -> Self {
        s.chars().collect()
    }
}

impl<T: Read> Read for Vec<T> {
    fn read(s: &str) -> Self {
        s.split_whitespace().map(T::read).collect()
    }
}

impl<A: Read, B: Read> Read for (A, B) {
    fn read(s: &str) -> Self {
        let tokens: Vec<_> = s.split_whitespace().collect();
        (A::read(tokens[0]), B::read(tokens[1]))
    }
}

impl<A: Read, B: Read, C: Read> Read for (A, B, C) {
    fn read(s: &str) -> Self {
        let tokens: Vec<_> = s.split_whitespace().collect();
        (A::read(tokens[0]), B::read(tokens[1]), C::read(tokens[2]))
    }
}

impl<A: Read, B: Read, C: Read, D: Read> Read for (A, B, C, D) {
    fn read(s: &str) -> Self {
        let tokens: Vec<_> = s.split_whitespace().collect();
        (A::read(tokens[0]), B::read(tokens[1]), C::read(tokens[2]), D::read(tokens[3]))
    }
}