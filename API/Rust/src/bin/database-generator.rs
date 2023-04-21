use std::fs::File;
use std::io::{Write, BufReader, BufRead, Error};
use linecount::count_lines;

fn get_number_of_lines(transport_file_path: String) -> usize {
    let input = File::open(transport_file_path)?;
    let number_of_lines: usize = count_lines(input.unwrap()).unwrap();
    number_of_lines;
}

fn lines_from_file(path: String) -> Vec<String> {
    let input = File::open(path)?;
    let buffered = BufReader::new(input);
    buffered.lines()
        .map(|l| l.expect("Could not parse line"))
        .collect();
}

fn read_transport(path: String) -> Vec::<(String,i32,f64,f64,f64,f64,f64,f64)> {
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

fn read_thermo(path: String, NC: usize) -> Vec::<(String,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64)> {
    let allv = Vec::<(String,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64)>::new();

    let lines = lines_from_file(path);

    for i in 0..lines.len(){
        j = NC*i

        let mut parts1 = lines[j+1].split_whitespace();
        let mut parts2 = lines[j+2].split_whitespace();
        let mut parts3 = lines[j+3].split_whitespace();

        let tuple = (lines[j],
            parts1.next().unwrap().parse::<f64>().unwrap(),
            parts1.next().unwrap().parse::<f64>().unwrap(),
            parts1.next().unwrap().parse::<f64>().unwrap(),
            parts1.next().unwrap().parse::<f64>().unwrap(),
            parts1.next().unwrap().parse::<f64>().unwrap(),
            parts2.next().unwrap().parse::<f64>().unwrap(),
            parts2.next().unwrap().parse::<f64>().unwrap(),
            parts2.next().unwrap().parse::<f64>().unwrap(),
            parts2.next().unwrap().parse::<f64>().unwrap(),
            parts2.next().unwrap().parse::<f64>().unwrap(),
            parts3.next().unwrap().parse::<f64>().unwrap(),
            parts3.next().unwrap().parse::<f64>().unwrap(),
            parts3.next().unwrap().parse::<f64>().unwrap(),
            parts3.next().unwrap().parse::<f64>().unwrap()
        )
        
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

*/
fn main() -> Result<(), Error> {
    let transport = read_transport("../../database/transport.asali".to_string());
    let NC = get_number_of_lines("../../database/transport.asali".to_string());
    let thermo = read_thermo("../../database/thermo.asali".to_string(), NC)

    Ok(())
}