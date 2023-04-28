use std::fs::File;
use std::io::{ self, BufRead, BufReader };
use std::process::exit;

fn read_lines(filename: String) -> io::Lines<BufReader<File>> {
    // Open the file in read-only mode.
    let file = File::open(filename).unwrap(); 
    // Read the file line by line, and return an iterator of the lines of the file.
    return io::BufReader::new(file).lines(); 
}

fn count_number_of_lines(filename: String) -> usize {
    let lines = read_lines(filename);
    return lines.count();
}

fn read_transport(path: String) -> Vec::<(String,i32,f64,f64,f64,f64,f64,f64)> {
    let lines = read_lines(path);

    let mut allv = Vec::<(String,i32,f64,f64,f64,f64,f64,f64)>::new();

    // Iterate over the lines of the file, and in this case print them.
    for line in lines {
        let lineu = line.unwrap();
        let mut parts = lineu.split_whitespace();
        let n_parts = lineu.split_whitespace().count();

        if n_parts != 8
        {
            println!("\nASALI::ERROR --> database/transport.asali missing parameter in line:\n {}", lineu);
            exit(-1);
        }

        let element = (
            parts.next().unwrap().to_string(), //AC3H4
            parts.next().unwrap().parse::<i32>().unwrap(), //1 
            parts.next().unwrap().parse::<f64>().unwrap(), //252.000
            parts.next().unwrap().parse::<f64>().unwrap(), //4.760
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //0.000
            parts.next().unwrap().parse::<f64>().unwrap(), //40.0648
        );

        if element.1 > 2
        {
            println!("\nASALI::ERROR --> database/transport.asali second paramter should be || 0 || 1 || 2 || in line:\n {}", lineu);
            exit(-1);
        }
        allv.push(element);
    }
    return allv;
}


fn read_thermo(path: String, NC: usize) -> Vec::<(String,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64)> {
    let mut allv = Vec::<(String,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64,f64)>::new();

    let mut lines = read_lines(path);

    let lines_vector: Vec<String> = lines.collect::<Result<_, _>>().unwrap();

    for i in 0..NC as usize {
        let mut line0 = &lines_vector[4*i];
        let mut line1 = &lines_vector[4*i+1];

        println!("{}, {}", line0, line1); //, line1.unwrap());
        

        /*

        let mut parts1 = line1.unwrap().split_whitespace();
        let mut parts2 = line2.unwrap().split_whitespace();
        let mut parts3 = line3.unwrap().split_whitespace();

        let element = (line0.unwrap(),
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
        );
        
        allv.push(element);*/
    }
    return allv;
}

fn main() {
    // Stores the iterator of lines of the file in lines variable.
    let transport = read_transport("../database/transport.asali".to_string());
    let NC = count_number_of_lines("../database/transport.asali".to_string());
    let thermo = read_thermo("../database/thermo.asali".to_string(), NC);
    println!("{}",NC);


    /*
    
    let NC = get_number_of_lines("../../database/transport.asali".to_string());
    let thermo = read_thermo("../../database/thermo.asali".to_string(), NC);*/
}