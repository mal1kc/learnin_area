use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("guest the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100);

    loop {
        println!("please input you guess: ");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!(
                "u idiot i want numbers this is not a number (maybe it is but not in this context)"
            );
                continue;
            }
        };

        println!("you guessed : {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("too smol!"),
            Ordering::Greater => println!("TOO BIG"),
            Ordering::Equal => {
                println!("you win!");
                break;
            }
        }
    }
}
