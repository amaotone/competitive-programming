#[allow(dead_code)]
const MOD: usize = 1_000000000 + 7;

fn main() {
    let mut cin = Scanner::new();
    let n = cin.next_usize();
    let mut t = (0..n).map(|_| cin.next_f64()).collect::<Vec<_>>();
    let mut v = (0..n).map(|_| cin.next_f64()).collect::<Vec<_>>();
    t.push(1.0);
    v.push(0.0);

    let mut ans: f64 = 0.0;
    let mut cur_v: f64 = 0.0;
    for i in 0..n {
        let mut acc_t = v[i] - cur_v;
        let mut dec_t = t[i];
        let mut sum_t = t[i];
        for j in i + 1..t.len() {
            if dec_t > sum_t - (v[i] - v[j]) {
                dec_t = sum_t - (v[i] - v[j]);
            }
            sum_t += t[j];
        }
        if acc_t > dec_t {
            acc_t = (acc_t + dec_t) / 2.0;
            dec_t = acc_t;
        }
        if acc_t > t[i] {
            acc_t = t[i];
            dec_t = acc_t;
        }
        ans += cur_v * acc_t + acc_t * acc_t / 2.0;
        cur_v += acc_t;
        ans += cur_v * (dec_t - acc_t);
        ans += cur_v * (t[i] - dec_t) - (t[i] - dec_t) * (t[i] - dec_t) / 2.0;
        cur_v -= (t[i] - dec_t);
    }

    println!("{:.9}", ans);
}


struct Scanner {
    reader: std::io::Stdin,
    tokens: std::collections::VecDeque<String>,
}

impl Scanner {
    fn new() -> Self {
        Scanner {
            reader: std::io::stdin(),
            tokens: std::collections::VecDeque::new(),
        }
    }

    fn next(&mut self) -> String {
        if self.tokens.is_empty() {
            let mut s = String::new();
            loop {
                self.reader.read_line(&mut s).ok();
                let s = s.trim();
                if s.len() != 0 {
                    for it in s.split_whitespace() {
                        self.tokens.push_back(it.into())
                    }
                    break;
                }
            }
        }
        self.tokens.pop_front().unwrap()
    }

    fn next_generics<T>(&mut self) -> T where
        T: std::str::FromStr + std::marker::Copy,
        <T as std::str::FromStr>::Err: std::fmt::Debug
    {
        self.next().parse().unwrap()
    }

    #[allow(dead_code)]
    fn next_i32(&mut self) -> i32 { self.next_generics::<i32>() }
    #[allow(dead_code)]
    fn next_i64(&mut self) -> i64 { self.next_generics::<i64>() }
    #[allow(dead_code)]
    fn next_u64(&mut self) -> u64 { self.next_generics::<u64>() }
    #[allow(dead_code)]
    fn next_f64(&mut self) -> f64 { self.next_generics::<f64>() }
    #[allow(dead_code)]
    fn next_usize(&mut self) -> usize { self.next_generics::<usize>() }
    #[allow(dead_code)]
    fn next_isize(&mut self) -> isize { self.next_generics::<isize>() }
}