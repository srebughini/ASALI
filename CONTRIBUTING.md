# Contributing to ASALI

Thank you for contributing to ASALI! We appreciate your help, as this is largely a volunteer effort.

You do not need to know the whole code base. Small fixes to documentation, examples and tests are valuable contributions, and they are a good way to make a first pull request.

## The ASALI ecosystem

ASALI is split over three repositories. Pick the one that matches your change.

| Repository | What it contains | Contribute here if you want to... |
|---|---|---|
| [ASALI](https://github.com/srebughini/ASALI) (this repository) | `GUI/`: the desktop application (Python, uses Cantera). `API/`: the thermodynamic and transport property library in C, C++, Fortran, Java, Julia, Matlab, Octave, Python and Rust. | change the GUI, or a property calculation, example or documentation in one of these languages |
| [ASALIPY](https://github.com/srebughini/ASALIPY) | Chemical reactor models in Python (needs conda, Cantera and Assimulo). | work on reactor models (see its `CONTRIBUTING.md`) |
| [JASALI](https://github.com/srebughini/JASALI) | JavaScript version of the property library, with tests. | work on the JavaScript version |

The `API/` implementations are separate code bases that calculate the same properties. A formula fix in one language often has to be checked in the others, and they do not share tests yet. Please say in your pull request which languages you checked.

## Find something to work on

1. Browse the [open issues](https://github.com/srebughini/ASALI/issues). Look for the labels `good first issue` and `help wanted`.
2. Before you start, check that nobody else is on it: read the comments of the issue and look at the [open pull requests](https://github.com/srebughini/ASALI/pulls).
3. Leave a short comment saying that you would like to work on the issue. If you have a question, ask it in the same issue.

## Set up and build

Run these commands from the folder shown. They were tested on Ubuntu 24.04. The `compile.sh` scripts use relative paths, so run them from inside the language folder.

| Part | Requirements | Build and run | Tested |
|---|---|---|---|
| C++ (`API/Cpp`) | `g++` | `./compile.sh && ./example` | Yes |
| C (`API/C`) | `gcc` | `./compile.sh && ./example` | Yes (GCC 14.2). The script stops if either build command fails. |
| Fortran (`API/Fortran`) | `gfortran` (provides the `f95` and `f77` commands the script calls) | `./compile.sh && ./example` | Yes |
| Java (`API/Java`) | JDK (tested with 21) | `./compile.sh && java Example` | Yes |
| Rust (`API/Rust`) | `cargo` (tested with 1.75) | `cargo build`, then `cargo run --bin asali` | Yes |
| Python (`API/Python`) | Python 3 and NumPy | `python3 example.py` | Yes |
| Julia, Matlab, Octave (`API/Julia`, `API/Matlab`, `API/Octave`) | the respective interpreter | see the sections of `API/README.md` | No |
| GUI (`GUI/`) | Anaconda | `conda env create -f environment.yml`, `conda activate asaligui`, `python app.py` (from `GUI/README.md`) | No |
| JavaScript | see [JASALI](https://github.com/srebughini/JASALI) | `npm install`, then `npm test` | Yes (80 tests pass) |

To regenerate the database code of a language, use the commands in the corresponding section of `API/README.md`. The generators read the files in `API/database`, so run them inside a full checkout.

On Windows, `compile.bat` is documented in `API/README.md`.

## Tests

Run `sh API/C/test_compile.sh` from the repository root to check the C build script's success and failure paths without a compiler or database files. There is no comprehensive automated API test suite or continuous integration for this repository yet. The JavaScript version (JASALI) and ASALIPY have their own tests. Because of this, the examples in each `API/<language>` folder are currently the main way to check a change.

What we ask for in a pull request:

- For a bug fix, a small program or test that fails before and passes after the change, and the exact command and output in the pull request description.
- Run the example of the language you changed before and after your change, and confirm that its output is unchanged unless the change is meant to alter it.
- If you change a formula, say whether you checked another language's implementation.

## Reporting bugs

Before creating a bug report, please do at least a cursory check that the bug has not already been reported. If it has, add a comment to the existing issue instead of opening a new one.

Bugs are tracked as [GitHub issues](https://github.com/srebughini/ASALI/issues). The repository has issue templates for a bug report, a feature request and a general issue; please use the one that fits.

Explain the problem and include details that help us reproduce it:

* Use a clear and descriptive title.
* Describe the exact steps that reproduce the problem.
* Describe the behavior you see after these steps.
* Describe the behavior you expect to see.
* Attach the files needed to reproduce the bug to the issue. If they cannot be shared publicly, contact the maintainers (see the contacts in the `README.md`).

The answers to these questions help too:

* What is the name and version of your operating system?
* Which language and compiler or interpreter (with version) are you using?
* How did you build ASALI (if you use the development version)?

For questions and clarifications, open an issue with the general issue template, or write to the contacts listed in the `README.md`.

## Submitting changes

Changes to ASALI should be submitted as [pull requests](https://github.com/srebughini/ASALI/pulls) against the `master` branch.

* Fork the repository into your GitHub account.
* Clone the forked repository to your local machine and make the changes. Keep each pull request focused on one issue.
* Commit and push the changes to GitHub.
* Open a new [GitHub pull request](https://github.com/srebughini/ASALI/pulls).
* Ensure the pull request description clearly describes the problem and the solution. Include the relevant issue number.

Some files (for example `API/C/example.c` and `API/Cpp/example.cpp`) use Windows (CRLF) line endings. Please keep the line endings of the files you edit, so that the diff only shows your change.

### Git commit messages

* Use the present tense ("Add feature", not "Added feature").
* Use the imperative mood ("Move cursor to...", not "Moves cursor to...").
* Reference issues and pull requests liberally.

### Pull request messages

* Rename the pull request and provide a comment that summarizes what the pull request changes or adds. This helps us summarize what changed between ASALI releases.

## Code style and review

The project has not defined a code style, a formatter or a review process. Please follow the style of the file you are editing, and avoid reformatting code that your change does not touch. Questions about conventions can be asked in the issue.

## Code of conduct

Please read our [Code of Conduct](CODE_OF_CONDUCT.md).
