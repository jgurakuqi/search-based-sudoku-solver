#include <iostream>
#include "constraint_propagation_based_solver.cpp"
using namespace std;

/**
 * @brief This method prints the content of the vector values.
 *
 * @tparam T
 * @param stream
 * @param values
 * @return ostream&
 */
template <class T>
ostream &operator<<(ostream &stream, const std::vector<T> &values)
{
	for (auto &value : values)
	{
		stream << value << " ";
	}
	// stream << '\n';
	return stream;
}

/**
 * @brief The following function performs the constraint propagation over the column, row and block related
 * to the cell [row][col], removing it's value from any domain
 *
 * @param sudokuField
 * @param domainsMatrix
 * @param row
 * @param col
 */
void updateDomains(vector<vector<int>> &sudokuField, vector<vector<vector<int>>> &domainsMatrix, int row, int col)
{
	int blockRowStart, blockColStart;
	// Domain deallocation
	domainsMatrix[row][col].resize(0);
	// Row and column control
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		if (sudokuField[row][i] == 0 && i != col)
		{
			domainsMatrix[row][i].erase(
				remove(
					domainsMatrix[row][i].begin(),
					domainsMatrix[row][i].end(),
					sudokuField[row][col]),
				domainsMatrix[row][i].end());
		}
		if (sudokuField[i][col] == 0 && i != row)
		{
			domainsMatrix[i][col].erase(
				remove(
					domainsMatrix[i][col].begin(),
					domainsMatrix[i][col].end(),
					sudokuField[row][col]),
				domainsMatrix[i][col].end());
		}
	}
	// Block control
	blockRowStart = row - (row % 3);
	blockColStart = col - (col % 3);
	for (int i = blockRowStart; i < (blockRowStart + 2); i++)
	{
		for (int j = blockColStart; j < (blockColStart + 2); j++)
		{
			if (sudokuField[i][j] == 0 && i != row && j != col)
			{
				domainsMatrix[i][j].erase(
					remove(
						domainsMatrix[i][j].begin(),
						domainsMatrix[i][j].end(),
						sudokuField[row][col]),
					domainsMatrix[i][j].end());
			}
		}
	}
};

void initializeDomainsMatrix(vector<vector<int>> &sudokuField, vector<vector<vector<int>>> &domainsMatrix)
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (sudokuField[i][j] != 0)
			{
				updateDomains(sudokuField, domainsMatrix, i, j);
			}
		}
	}
};

int main()
{
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

	vector<vector<vector<int>>> domainsMatrix(FIELD_SIZE, vector<vector<int>>(FIELD_SIZE, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
	vector<vector<vector<int>>> domainsMatrix2(FIELD_SIZE, vector<vector<int>>(FIELD_SIZE, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));

	initializeDomainsMatrix(sudokuField, domainsMatrix);
	initializeDomainsMatrix(sudokuField2, domainsMatrix2);

	// cout << sudokuField;
	// cout << domainsMatrix;

	for (int i = 0; i < FIELD_SIZE; i++)
	{
		cout << "{ ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			cout << domainsMatrix[i][j] << ", ";
		}
		cout << " }\n";
	}
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		cout << "{ ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			cout << domainsMatrix2[i][j] << ", ";
		}
		cout << " }\n";
	}

	cout << solveSudoku(sudokuField, domainsMatrix);
	return 0;
}