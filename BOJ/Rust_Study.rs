use std::io;

fn main() {
    let mut days = String::new();
    
    io::stdin().read_line(&mut days).unwrap();

    let mut days:i32 = days.trim().parse().unwrap();

    let mut sched_page = String::new();
    let mut study_page = String::new();

    io::stdin().read_line(&mut sched_page).unwrap();
    io::stdin().read_line(&mut study_page).unwrap();
    
    let sched_page:Vec<i32> = sched_page
                              .split_whitespace()
                              .map(|s| s.parse().unwrap())
                              .collect();

    let study_page:Vec<i32> = study_page
                              .split_whitespace()
                              .map(|s| s.parse().unwrap())
                              .collect();
    
    let mut count = 0;

    loop {
        if days == 0 {
            break;
        }
        
        let a = study_page[(days - 1) as usize];
        let b = sched_page[(days - 1) as usize];
        if  a <= b {
            count += 1;
        }

        days -= 1;
    }

    println!("{count}");
}
