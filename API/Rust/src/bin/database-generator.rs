use std::fs::File;
use std::io::{ self, BufRead, BufReader };
use std::process::exit;
use std::str::SplitWhitespace;

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

    let lines = read_lines(path);
    let lines_vector: Vec<String> = lines.collect::<Result<_, _>>().unwrap();

    for i in 0..NC as usize {
        let line0 = &lines_vector[4*i];
        let mut parts1 = lines_vector[4*i+1].split_whitespace();
        let mut parts2 = lines_vector[4*i+2].split_whitespace();
        let mut parts3 = lines_vector[4*i+3].split_whitespace();

        let element = (line0.to_string(),
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
        
        allv.push(element);
    }
    return allv;
}

fn read_matrix(path: String) -> (Vec<f64>, Vec<f64>, Vec<Vec<f64>>) {
    let lines = read_lines(path);
    let lines_vector: Vec<String> = lines.collect::<Result<_, _>>().unwrap();

    let mut t = Vec::<f64>::new();
    let mut d = Vec::<f64>::new();
    let mut s = Vec::<Vec::<f64>>::new();

    // Read d
    let mut parts = lines_vector[0].split_whitespace();
    let mut parts_vector: Vec<String> = parts.map(|s| s.to_string()).collect();

    for k in 1..9 as usize {
        d.push(parts_vector[k].parse::<f64>().unwrap());
    }

    // Read t and s
    for i in 1..lines_vector.len() as usize {
        parts = lines_vector[i].split_whitespace();
        parts_vector = parts.map(|s| s.to_string()).collect();

        t.push(parts_vector[0].parse::<f64>().unwrap());

        let mut sVector = Vec::<f64>::new();
        for k in 0..9 as usize {
            sVector.push(parts_vector[k].parse::<f64>().unwrap());
        }

        s.push(sVector);
    }

    return (d, t, s);

}

fn main() {
    let transport_file = read_transport("../database/transport.asali".to_string());
    let NC = count_number_of_lines("../database/transport.asali".to_string());
    let thermo_file = read_thermo("../database/thermo.asali".to_string(), NC);
    let astar_file = read_matrix("../database/astar.asali".to_string());
    let omega22_file = read_matrix("../database/omega22.asali".to_string());
}