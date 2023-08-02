
# Constraint Propagation approach

- Create a matrix class, which will be used to create sudoku fields and to store the domains of each 
  empty cell.
- Solve the problem using a Forward Checking approach, where every variable will have a domain, to be 
  updated on each "move", in order to detect any constraint violation. In case of constraint violation,
  there will be a backtracking, reaching the most recent "snapshot" of the field, to proceed with other
  values.

# Relaxation Labeling approach



## Table of Contents

- [Requirements](#Requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)


## Requirements

Write a solver for sudoku puzzles using a constraint satisfaction approach based on constraint propagation and backtracking, and one based on Relaxation Labeling. compare the approaches, their strengths and weaknesses.

A sudoku puzzle is composed of a square 9x9 board divided into 3 rows and 3 columns of smaller 3x3 boxes. The goal is to fill the board with digits from 1 to 9 such that

each number appears only once for each row column and 3x3 box;
each row, column, and 3x3 box should containg all 9 digits.
The solver should take as input a matrix withwhere empty squares are represented by a standars symbol (e.g., ".", "_", or "0"), while known square should be represented by the corresponding digit (1,...,9). For example:
                                            37. 5.. ..6
                                            ... 36. .12
                                            ... .91 75.
                                            ... 154 .7.
                                            ..3 .7. 6..
                                            .5. 638 ...
                                            .64 98. ...
                                            59. .26 ...
                                            2.. ..5 .64

# Hints for Constraint Propagation and Backtracking:
- Each cell should be a variable that can take values in the domain (1, … ,9).
- The two types of constraints in the definition form as many types of constraints:
  - Direct constraints impose that no two equal digits appear for each row, column, and box.
  - Indirect constrains impose that each digit must appear in each row, column, and box.
- You can think of other types of (pairwise) constraints to further improve the constraint propagation phase.
- Note: most puzzles found in the magazines can be solved with only the constraint propagation step.

# Hints for Relaxation Labeling:
- Each cell should be an object, the values between 1 and 9 labels.
- The compatibility 𝑟𝑖𝑗(𝜆, 𝜇) should be 1 if the assignments satisfy direct constraints, 0 otherwise.

## Installation

In order to run this project a Python 3 and a basic C++ compiler are required, and also Python 3 requires the installation of the numpy module:
```bash
pip3 install numpy
```

## Usage

In order to run the Constraint Propagation based solver:
```bash
g++ main.cpp -o out
./out
```

For the Relaxation labeling based solver:
```bash
python main.py
```

# Contributing

```bash
git clone https://github.com/jgurakuqi/search-based-sudoku-solver
```

# License

MIT License

Copyright (c) 2022 Jurgen Gurakuqi

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
