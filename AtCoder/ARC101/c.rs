#![allow(dead_code, unused_imports, non_snake_case)]

use std::io::*;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::str::FromStr;

const MOD: i32 = 1_000_000_007;

fn main() {
    let (_, mut k): (usize, usize) = input();
    let t: Vec<i64> = input();
    let mut plus = Vec::new();
    let mut minus = Vec::new();
    for &x in &t {
        if x == 0 {
            k -= 1;
        } else if x < 0 {
            minus.push(x.abs() as usize);
        } else {
            plus.push(x.abs() as usize);
        }
    }
    plus.sort();
    minus.sort();

    if k == 0 {
        println!("0");
        return;
    }

    let mut ans: usize = 1 << 29;

    // 片方だけ
    if plus.len() >= k {
        ans = min(ans, plus[k - 1]);
    }
    if minus.len() >= k {
        ans = min(ans, minus[k - 1]);
    }

    // ターンする
    for i in 1..k {
        if i <= minus.len() && k - i <= plus.len() {
            ans = min(ans, minus[i - 1] * 2 + plus[k - i - 1]);
        }
        if i <= plus.len() && k - i <= minus.len() {
            ans = min(ans, plus[i - 1] * 2 + minus[k - i - 1]);
        }
    }
    println!("{}", ans);
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