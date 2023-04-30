use std::fs::File;
use std::io::{ self, BufRead, BufReader, Write };
use std::process::exit;
use std::str::SplitWhitespace;

fn read_lines(filename: String) -> io::Lines<BufReader<File>> {
    let file = File::open(filename).unwrap(); 
    return io::BufReader::new(file).lines(); 
}

fn count_number_of_lines(filename: String) -> usize {
    let lines = read_lines(filename);
    return lines.count();
}

fn read_transport(path: String) -> Vec::<(String,i32,f64,f64,f64,f64,f64,f64)> {
    let lines = read_lines(path);

    let mut allv = Vec::<(String,i32,f64,f64,f64,f64,f64,f64)>::new();

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
        for k in 1..9 as usize {
            sVector.push(parts_vector[k].parse::<f64>().unwrap());
        }

        s.push(sVector);
    }

    return (d, t, s);
}


fn transport_to_file(input_path: String, output_path: String) {
    let as_file = read_transport(input_path);

    let mut as_string = "use crate::definitions::Transport;\npub fn transport_update(transport: &mut Vec<Transport>) {".to_string();

    for i in 0..as_file.len() as usize {
        let specie_string = format!("\nlet t = Transport {{\nname: \"{}\".to_string(),\ngeometry: {},\nljpotential: {:?},\nljdiameter: {:?},\ndipole: {:?},\npolar: {:?},\ncollision: {:?},\nmw: {:?}\n}};\ntransport.push(t);\n", 
        as_file[i].0, 
        as_file[i].1,
        as_file[i].2,
        as_file[i].3,
        as_file[i].4,
        as_file[i].5,
        as_file[i].6,
        as_file[i].7);

        as_string.push_str(&specie_string);
    }

    as_string.push_str("}");
    
    let mut data_file = File::create(output_path).expect("ASALI::ERROR-->transport file creation failed");
    data_file.write(as_string.as_bytes()).expect("ASALI::ERROR-->transport file write failed");
}

fn thermo_to_file(input_path: String, output_path: String, NC: usize) {
    let as_file = read_thermo(input_path, NC);

    let mut as_string = "use crate::definitions::Thermo;\npub fn thermo_update(thermo: &mut Vec<Thermo>) {".to_string();

    for i in 0..as_file.len() as usize {
        let specie_string = format!("\nlet t = Thermo{{\nname: \"{}\".to_string(),\nhigh: [{:?},{:?},{:?},{:?},{:?},{:?},{:?}],\nlow:  [{:?},{:?},{:?},{:?},{:?},{:?},{:?}]\n}};\nthermo.push(t);",
        as_file[i].0,
        as_file[i].1,
        as_file[i].2,
        as_file[i].3,
        as_file[i].4,
        as_file[i].5,
        as_file[i].6,
        as_file[i].7,
        as_file[i].8,
        as_file[i].9,
        as_file[i].10,
        as_file[i].11,
        as_file[i].12,
        as_file[i].13,
        as_file[i].14);

        as_string.push_str(&specie_string);
    }

    as_string.push_str("}");
    
    let mut data_file = File::create(output_path).expect("ASALI::ERROR-->thermo file creation failed");
    data_file.write(as_string.as_bytes()).expect("ASALI::ERROR-->thermo file write failed");
}


fn omega_to_file(omega_path: String, 
                  astar_path: String, 
                  output_path: String) {
    let omega_as_file = read_matrix(omega_path);
    let astar_as_file = read_matrix(astar_path);

    let mut as_string = "use crate::definitions::Omega;\npub fn omega22_update() -> Omega {".to_string();

    let o22 = format!("\nlet omega = Omega {{\nd: {:?},\nt: {:?},\nsigma: {:?}\n}};\nreturn omega;", 
                            omega_as_file.0, 
                            omega_as_file.1, 
                            omega_as_file.2);
    
    as_string.push_str(&o22);
    as_string.push_str("}");
    
    as_string.push_str("\npub fn omega11_update() -> Omega {");

    let mut s11 = astar_as_file.2;

    for i in 0..s11.len() as usize {
        for k in 0..s11[i].len() as usize {
            s11[i][k] = omega_as_file.2[i][k]/s11[i][k];
        }
    }

    let o11 = format!("\nlet omega = Omega {{\nd: {:?},\nt: {:?},\nsigma: {:?}\n}};\nreturn omega;", 
                            astar_as_file.0, 
                            astar_as_file.1, 
                            s11);

    as_string.push_str(&o11);
    as_string.push_str("}");
    
    let mut data_file = File::create(output_path).expect("ASALI::ERROR-->omega file creation failed");
    data_file.write(as_string.as_bytes()).expect("ASALI::ERROR-->omega file write failed");

}


fn main() {
    transport_to_file("../database/transport.asali".to_string(), "src/transport.rs".to_string());
    
    let NC = count_number_of_lines("../database/transport.asali".to_string());
    thermo_to_file("../database/thermo.asali".to_string(), "src/thermo.rs".to_string(), NC);
    
    omega_to_file("../database/omega22.asali".to_string(), 
    "../database/astar.asali".to_string(), 
    "src/omega.rs".to_string());

}