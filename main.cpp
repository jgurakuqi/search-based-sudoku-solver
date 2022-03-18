
#include "constraint_propagation_based_solver.h"
#include "relaxation_labeling_based_solver.h"
using namespace std;

int main()
{
	// FUNZIONANTE
	vector<vector<int>> sudokuField{
		{3, 7, 0, 5, 0, 0, 0, 0, 6},
		{0, 0, 0, 3, 6, 0, 0, 1, 2},
		{0, 0, 0, 0, 9, 1, 7, 5, 0},
		{0, 0, 0, 1, 5, 4, 0, 7, 0},
		{0, 0, 3, 0, 7, 0, 6, 0, 0},
		{0, 5, 0, 6, 3, 8, 0, 0, 0},
		{0, 6, 4, 9, 8, 0, 0, 0, 0},
		{5, 9, 0, 0, 2, 6, 0, 0, 0},
		{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	vector<vector<int>> sudokuField2{
		{6, 7, 0, 5, 6, 0, 0, 0, 6},
		{0, 0, 0, 3, 6, 0, 0, 1, 2},
		{0, 0, 0, 0, 9, 1, 7, 5, 0},
		{0, 0, 0, 1, 5, 4, 0, 7, 0},
		{0, 0, 3, 0, 7, 0, 6, 0, 0},
		{0, 5, 0, 6, 3, 8, 0, 0, 0},
		{0, 6, 4, 9, 8, 0, 0, 0, 0},
		{5, 9, 0, 0, 2, 6, 0, 0, 0},
		{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	vector<vector<int>> sudokuField3{
		{6, 7, 0, 5, 0, 0, 0, 0, 6},
		{0, 0, 0, 3, 6, 0, 0, 1, 2},
		{0, 0, 0, 0, 9, 1, 7, 5, 0},
		{0, 0, 0, 1, 5, 4, 0, 7, 0},
		{0, 0, 3, 0, 7, 0, 6, 0, 0},
		{0, 5, 0, 6, 3, 8, 0, 0, 0},
		{0, 6, 4, 9, 8, 0, 0, 0, 0},
		{5, 9, 0, 0, 2, 6, 0, 0, 0},
		{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	vector<vector<int>> sudokuField4{
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}};

	vector<vector<int>> sudokuField5{
		{0, 0, 0, 0, 0, 0, 9, 0, 7},
		{0, 0, 0, 4, 2, 0, 1, 8, 0},
		{0, 0, 0, 7, 0, 5, 0, 2, 6},
		{1, 0, 0, 9, 0, 4, 0, 0, 0},
		{0, 5, 0, 0, 0, 0, 0, 4, 0},
		{0, 0, 0, 5, 0, 7, 0, 0, 9},
		{9, 2, 0, 1, 0, 8, 0, 0, 0},
		{0, 3, 4, 0, 5, 9, 0, 0, 0},
		{5, 0, 7, 0, 0, 0, 0, 0, 0}};

	cout << "\nSudokuField1:\n";
	printSudokuField(solveSudoku(sudokuField));
	cout << "\nSudokuField2:\n";
	printSudokuField(solveSudoku(sudokuField2));
	cout << "\nSudokuField3:\n";
	printSudokuField(solveSudoku(sudokuField3));
	cout << "\nSudokuField4:\n";
	printSudokuField(solveSudoku(sudokuField4));
	cout << "\nSudokuField5:\n";
	printSudokuField(solveSudoku(sudokuField5));
	return 0;
}