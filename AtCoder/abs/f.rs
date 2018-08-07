#![allow(dead_code, unused_imports, non_snake_case)]

use std::io::*;
use std::cmp::{max, min, Ordering};
use std::collections::*;
use std::str::FromStr;

const MOD: i32 = 1_000_000_007;

mod util {
    use std::fmt::Debug;
    use std::io::{stdin, stdout, BufWriter, StdoutLock};
    use std::str::FromStr;

    pub fn line() -> String {
        let mut line: String = String::new();
        stdin().read_line(&mut line).unwrap();
        line.trim().to_string()
    }

    pub fn chars() -> Vec<char> {
        line().chars().collect()
    }

    pub fn gets<T: FromStr>() -> Vec<T>
        where
            <T as FromStr>::Err: Debug,
    {
        let mut line: String = String::new();
        stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|t| t.parse().unwrap())
            .collect()
    }

    pub fn with_bufwriter<F: FnOnce(BufWriter<StdoutLock>) -> ()>(f: F) {
        let out = stdout();
        let writer = BufWriter::new(out.lock());
        f(writer)
    }
}

macro_rules! max {($x:expr)=>{$x};($x:expr,$($xs:tt)+)=>{max($x,max!($($xs)+))};}
macro_rules! min {($x:expr)=>{$x};($x:expr,$($xs:tt)+)=>{min($x,min!($($xs)+))};}
macro_rules! get {($t:ty)=>{{let mut line:String=String::new();stdin().read_line(&mut line).unwrap();line.trim().parse::<$t>().unwrap()}};($($t:ty),*)=>{{let mut line:String=String::new();stdin().read_line(&mut line).unwrap();let mut iter=line.split_whitespace();($(iter.next().unwrap().parse::<$t>().unwrap(),)*)}};($t:ty;$n:expr)=>{(0..$n).map(|_|get!($t)).collect::<Vec<_>>()};($($t:ty),*;$n:expr)=>{(0..$n).map(|_|get!($($t),*)).collect::<Vec<_>>()};($t:ty;;)=>{{let mut line:String=String::new();stdin().read_line(&mut line).unwrap();line.split_whitespace().map(|t|t.parse::<$t>().unwrap()).collect::<Vec<_>>()}};($t:ty;;$n:expr)=>{(0..$n).map(|_|get!($t;;)).collect::<Vec<_>>()};}
macro_rules! debug {($($a:expr),*)=>{eprintln!(concat!($(stringify!($a),"={:?},"),*),$($a),*);}}

fn main() {
    let (n, a, b) = get!(u32, u32, u32);
    let ans = (1..n+1).filter(|&x| {
        let sum = x.to_string().chars().map(|c| c.to_digit(10).unwrap()).sum::<u32>();
        a <= sum && sum <= b
    }).sum::<u32>();
    println!("{}", ans);
}