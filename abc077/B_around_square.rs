use std::io::{stdin, Read, StdinLock};
use std::str::FromStr;

struct Scanner<'a> {
    cin: StdinLock<'a>,
}

impl<'a> Scanner<'a> {
    fn new(cin: StdinLock<'a>) -> Scanner<'a> {
        Scanner { cin: cin }
    }

    fn read1<T: FromStr>(&mut self) -> Option<T> {
        let token = self.cin.by_ref().bytes().map(|c| c.unwrap() as char)
            .skip_while(|c| c.is_whitespace())
            .take_while(|c| !c.is_whitespace())
            .collect::<String>();
        token.parse::<T>().ok()
    }

    fn read<T: FromStr>(&mut self) -> T {
        self.read1().unwrap()
    }
}

fn main() {
    let cin = stdin();
    let cin = cin.lock();
    let mut sc = Scanner::new(cin);
    let n: i32 = sc.read();
    let mut ans = 0;
    for i in 1..40000 {
        if i * i <= n {
            ans = i * i;
        }
    }
    println!("{}", ans)
}
