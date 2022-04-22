use std::cmp::min;
use std::io;

fn solve(info: &Vec<Vec<i32>>, pos: i32, solved: i32, all: i32) -> i32 {
    if solved == all {
        return 0;
    }
    if pos >= info.len() as i32 {
        return 1000000;
    }
    let mut new_solved = solved;
    let mut ans = solve(&info, pos + 1, solved, all);
    let mut it = info[pos as usize].iter();
    it.next();
    while let Some(x) = it.next() {
        new_solved |= 1 << (*x - 1);
    }
    ans = min(ans, 1 + solve(&info, pos + 1, new_solved, all));
    ans
}
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let v = line
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<_>>();
    let (n, m) = (&v[0], &v[1]);

    let mut infos = Vec::new();
    for _ in 0..*m {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let info = line
            .trim()
            .split_whitespace()
            .map(|x| x.parse::<i32>().unwrap())
            .collect::<Vec<_>>();
        infos.push(info);
    }

    let all_solved = (1 << *n) - 1;
    let ans = solve(&infos, 0, 0, all_solved);
    match ans {
        big if big >= 1000000 => println!("-1"),
        _ => println!("{ans}"),
    }
}
