use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();


    // println!("{}", input);
    let mut iter = input.split_whitespace();
    let n:u32 = iter.next().unwrap().parse().unwrap();
    let mut a:Vec<u32> = vec![];
    for _ in 0..n {
        let v:u32 = iter.next().unwrap().parse().unwrap();
        a.push(v);
    }

    let mut b:Vec<u32> = vec![];
    for _ in 0..n {
        let v:u32 = iter.next().unwrap().parse().unwrap();
        b.push(v);
    }

    let mut succ:u32 = 0;
    for i in 0..n {
        if a[i as usize] <= b[i as usize] {

            succ += 1;
        }
    }


    println!("{}", succ);
    

}