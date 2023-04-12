use std::fs::File;
use std::io::{Write, BufReader, BufRead, Error};


fn read_transport() -> Vec::<(String,i32,f64,f64,f64,f64,f64,f64)> {
    let path = "../../database/transport.asali";
    let input = File::open(path)?;
    let buffered = BufReader::new(input);

    let allv = Vec::<(String,i32,f64,f64,f64,f64,f64,f64)>::new();

    for line in buffered.lines() { 
        let mut parts = line.split_whitespace();

        if parts.len() != 8
        {
            println!("\nASALI::ERROR --> database/transport.asali missing parameter in line:\n {}", line);
            exit(-1);
        }

        let tuple = (
            parts.next().unwrap().to_string(), //AC3H4
            parts.next().unwrap().parse::<i32>().unwrap(), //1 
            parts.next().unwrap().parse::<f64>().unwrap(), //252.000
            parts.next().unwrap().parse::<f64>().unwrap(), //4.760
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //40.0648
        );

        if tuple.1 > 2
        {
            println!("\nASALI::ERROR --> database/transport.asali second paramter should be || 0 || 1 || 2 || in line:\n {}", line);
            exit(-1);
        }

        allv.push(tuple);
    }
    allv;
}

/*
fn read_astar() -> Result<(), Error> {
    let path = "../../database/astar.asali";
    let input = File::open(path)?;
    let buffered = BufReader::new(input);

    for line in buffered.lines() {
        println!("{}", line?);
    }
}


fn main() -> Result<(), Error> {
    

    //let mut output = File::create(path)?;
    //write!(output, "Rust\n💖\nFun")?;

    
    let buffered = BufReader::new(input);

    for line in buffered.lines() {
        println!("{}", line?);
    }

    Ok(())
}
*/