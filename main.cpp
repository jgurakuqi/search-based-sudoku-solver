
#include <chrono>
#include "constraint_propagation_based_solver.h"
#include "relaxation_labeling_based_solver.h"
using namespace std;
using namespace std::chrono;

int main()
{
	int2DMatrix inputSudokuExample = {
		{3, 7, 0, 5, 0, 0, 0, 0, 6},
		{0, 0, 0, 3, 6, 0, 0, 1, 2},
		{0, 0, 0, 0, 9, 1, 7, 5, 0},
		{0, 0, 0, 1, 5, 4, 0, 7, 0},
		{0, 0, 3, 0, 7, 0, 6, 0, 0},
		{0, 5, 0, 6, 3, 8, 0, 0, 0},
		{0, 6, 4, 9, 8, 0, 0, 0, 0},
		{5, 9, 0, 0, 2, 6, 0, 0, 0},
		{2, 0, 0, 0, 0, 5, 0, 6, 4},
	};

	int2DMatrix easySudoku1 = {
		{6, 0, 8, 0, 0, 0, 9, 0, 4},
		{2, 0, 0, 0, 1, 4, 0, 5, 0},
		{0, 0, 7, 9, 8, 3, 0, 0, 0},
		{0, 2, 0, 5, 0, 0, 0, 0, 9},
		{0, 3, 9, 4, 0, 8, 5, 1, 0},
		{8, 0, 0, 0, 0, 9, 0, 7, 0},
		{0, 0, 0, 3, 9, 2, 7, 0, 0},
		{0, 5, 0, 7, 4, 0, 0, 0, 8},
		{9, 0, 4, 0, 0, 0, 3, 0, 6},
	};

	int2DMatrix easySudoku2 = {
		{0, 5, 0, 0, 9, 0, 0, 0, 0},
		{0, 0, 4, 8, 0, 0, 0, 0, 9},
		{0, 0, 0, 1, 0, 7, 2, 8, 0},
		{5, 6, 0, 0, 0, 0, 1, 3, 7},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 7, 3, 0, 0, 0, 0, 4, 2},
		{0, 2, 1, 5, 0, 8, 0, 0, 0},
		{6, 0, 0, 0, 0, 3, 8, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 6, 0},
	};

	int2DMatrix easySudoku3 = {
		{0, 4, 0, 0, 0, 0, 1, 7, 9},
		{0, 0, 2, 0, 0, 8, 0, 5, 4},
		{0, 0, 6, 0, 0, 5, 0, 0, 8},
		{0, 8, 0, 0, 7, 0, 9, 1, 0},
		{0, 5, 0, 0, 9, 0, 0, 3, 0},
		{0, 1, 9, 0, 6, 0, 0, 4, 0},
		{3, 0, 0, 4, 0, 0, 7, 0, 0},
		{5, 7, 0, 1, 0, 0, 2, 0, 0},
		{9, 2, 8, 0, 0, 0, 0, 6, 0},
	};
	int2DMatrix mediumSudoku = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 7, 9, 0, 5, 0, 1, 8, 0},
		{8, 0, 0, 0, 0, 0, 0, 0, 7},
		{0, 0, 7, 3, 0, 6, 8, 0, 0},
		{4, 5, 0, 7, 0, 8, 0, 9, 6},
		{0, 0, 3, 5, 0, 2, 7, 0, 0},
		{7, 0, 0, 0, 0, 0, 0, 0, 5},
		{0, 1, 6, 0, 3, 0, 4, 2, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	int2DMatrix mediumSudoku1 = {
		{0, 0, 0, 4, 0, 0, 3, 7, 0},
		{8, 0, 1, 0, 0, 0, 0, 2, 0},
		{7, 4, 3, 9, 0, 8, 0, 0, 0},
		{3, 0, 0, 0, 7, 0, 9, 8, 0},
		{0, 0, 6, 0, 0, 0, 0, 5, 0},
		{0, 0, 0, 0, 4, 0, 6, 0, 3},
		{5, 3, 0, 2, 0, 4, 0, 0, 0},
		{0, 0, 0, 0, 9, 0, 7, 4, 0},
		{9, 0, 0, 0, 5, 0, 0, 3, 0},
	};

	int2DMatrix difficultSudoku = {
		{6, 0, 0, 1, 0, 7, 0, 0, 4},
		{0, 0, 5, 0, 4, 0, 0, 0, 0},
		{0, 2, 7, 0, 6, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 5, 0, 7, 0},
		{0, 9, 0, 0, 3, 0, 0, 0, 2},
		{0, 0, 2, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 0, 0, 6, 0, 0, 5},
		{0, 0, 0, 0, 5, 1, 0, 0, 6},
		{2, 0, 0, 4, 0, 0, 8, 0, 0},
	};

	int2DMatrix veryDifficultSudoku = {
		{0, 0, 0, 0, 0, 0, 0, 8, 5},
		{0, 0, 0, 2, 1, 0, 0, 0, 9},
		{9, 6, 0, 0, 8, 0, 1, 0, 0},
		{5, 0, 0, 8, 0, 0, 0, 1, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{8, 9, 0, 0, 6, 0, 0, 0, 7},
		{0, 0, 9, 0, 7, 0, 0, 5, 2},
		{3, 0, 0, 0, 5, 4, 0, 0, 0},
		{4, 8, 0, 0, 0, 0, 0, 0, 0},
	};

	int2DMatrix emptySudoku = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	int2DMatrix evilSudoku = {
		{0, 2, 0, 0, 6, 0, 0, 0, 0},
		{0, 0, 7, 4, 0, 2, 0, 0, 3},
		{0, 0, 0, 0, 8, 0, 4, 0, 0},
		{0, 9, 0, 2, 0, 3, 1, 0, 0},
		{0, 0, 8, 0, 0, 0, 0, 9, 0},
		{0, 0, 0, 0, 0, 6, 0, 0, 0},
		{0, 8, 0, 1, 0, 9, 3, 0, 0},
		{5, 0, 0, 0, 0, 0, 0, 0, 7},
		{0, 0, 0, 0, 4, 0, 0, 0, 0},
	};

	// // FUNZIONANTE
	// int2DMatrix sudokuField{
	// 	{3, 7, 0, 5, 0, 0, 0, 0, 6},
	// 	{0, 0, 0, 3, 6, 0, 0, 1, 2},
	// 	{0, 0, 0, 0, 9, 1, 7, 5, 0},
	// 	{0, 0, 0, 1, 5, 4, 0, 7, 0},
	// 	{0, 0, 3, 0, 7, 0, 6, 0, 0},
	// 	{0, 5, 0, 6, 3, 8, 0, 0, 0},
	// 	{0, 6, 4, 9, 8, 0, 0, 0, 0},
	// 	{5, 9, 0, 0, 2, 6, 0, 0, 0},
	// 	{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	// int2DMatrix sudokuField2{
	// 	{6, 7, 0, 5, 6, 0, 0, 0, 6},
	// 	{0, 0, 0, 3, 6, 0, 0, 1, 2},
	// 	{0, 0, 0, 0, 9, 1, 7, 5, 0},
	// 	{0, 0, 0, 1, 5, 4, 0, 7, 0},
	// 	{0, 0, 3, 0, 7, 0, 6, 0, 0},
	// 	{0, 5, 0, 6, 3, 8, 0, 0, 0},
	// 	{0, 6, 4, 9, 8, 0, 0, 0, 0},
	// 	{5, 9, 0, 0, 2, 6, 0, 0, 0},
	// 	{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	// int2DMatrix sudokuField3{
	// 	{6, 7, 0, 5, 0, 0, 0, 0, 6},
	// 	{0, 0, 0, 3, 6, 0, 0, 1, 2},
	// 	{0, 0, 0, 0, 9, 1, 7, 5, 0},
	// 	{0, 0, 0, 1, 5, 4, 0, 7, 0},
	// 	{0, 0, 3, 0, 7, 0, 6, 0, 0},
	// 	{0, 5, 0, 6, 3, 8, 0, 0, 0},
	// 	{0, 6, 4, 9, 8, 0, 0, 0, 0},
	// 	{5, 9, 0, 0, 2, 6, 0, 0, 0},
	// 	{2, 0, 0, 0, 0, 5, 0, 6, 4}};

	// int2DMatrix sudokuField4{
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0}};

	steady_clock::time_point begin = steady_clock::now();

	printSudokuField(solveSudoku(easySudoku1));
	cout << "\n";
	printSudokuField(solveSudoku(mediumSudoku1));
	cout << "\n";
	printSudokuField(solveSudoku(difficultSudoku));
	cout << "\n";
	printSudokuField(solveSudoku(evilSudoku));

	steady_clock::time_point end = steady_clock::now();
	double elapsedTime = static_cast<double>(duration_cast<microseconds>(end - begin).count()) / 1000000;
	cout << "Elapsed time = " << elapsedTime << " seconds.\n";
	// cout << "Elapsed time = " << duration_cast<nanoseconds>(end - begin).count() << "[ns]" << std::endl;
	return 0;
}