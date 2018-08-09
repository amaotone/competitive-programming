#![allow(dead_code, unused_imports, non_snake_case)]

use std::io::*;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::str::FromStr;

const MOD: i32 = 1_000_000_007;

fn main() {
    let (a, b): (usize, usize) = input();
    let A: Vec<u32> = input();
    let B: Vec<u32> = input();
    let mut dp = vec![vec![0; b + 1]; a + 1];

    // 片方しか無いとき
    for i in 1..a + 1 {
        if (a + b - i) % 2 == 0 {
            dp[i][0] = dp[i - 1][0] + A[a - i];
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for j in 1..b + 1 {
        if (a + b - j) % 2 == 0 {
            dp[0][j] = dp[0][j - 1] + B[b - j];
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for i in 1..a + 1 {
        for j in 1..b + 1 {
            if (a + b - i - j) % 2 == 0 {
                dp[i][j] = max(dp[i - 1][j] + A[a - i], dp[i][j - 1] + B[b - j]);
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    println!("{}", dp[a][b]);
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