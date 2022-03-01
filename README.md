# search_based_sudoku_solver
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


# Constraint Propagation approach

- Create a matrix class, which will be used to create sudoku fields and to store the domains of each 
  empty cell.
- Solve the problem using a Forward Checking approach, where every variable will have a domain, to be 
  updated on each "move", in order to detect any constraint violation. In case of constraint violation,
  there will be a backtracking, reaching the most recent "snapshot" of the field, to proceed with other
  values.

# Relaxation Labeling approach