#[allow(unused_imports, non_snake_case)]
use std::io::*;
use std::collections::*;
use std::str::FromStr;

#[arrow(dead_code)]
fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char)
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")    
}

fn main() {
    let n = read::<usize>();
    let s = read::<String>().chars().collect()::<Vec<char>>();
    let mut cnts = HashMap::<(Vec<char>, Vec<char>), usize>::new();
    for i in 0..1<<n {
        let mut red = vec![];
        let mut blue = vec![];
        for j in 0..n {
            
        }    
    }
}