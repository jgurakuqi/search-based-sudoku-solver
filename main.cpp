
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

	printSudokuField(solveSudoku(sudokuField));
	cout << "\n";
	printSudokuField(solveSudoku(sudokuField2));
	cout << "\n";
	printSudokuField(solveSudoku(sudokuField3));
	cout << "\n";
	printSudokuField(solveSudoku(sudokuField4));
	return 0;
}