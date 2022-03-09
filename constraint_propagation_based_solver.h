#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#define FIELD_SIZE 9

using namespace std;

/**
 * @brief Defined aliases for vector<vector<int>> and vector<vector<vector<int>>>
 *
 */
typedef std::vector<std::vector<int>> int2DMatrix;
typedef vector<int2DMatrix> int3DMatrix;

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

void printSudokuField(int2DMatrix sudokuField)
{
    if (sudokuField.empty())
    {
        return;
    }
    int j;
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        cout << "| ";
        for (j = 0; j < FIELD_SIZE; j++)
        {
            cout << sudokuField[i][j] << " ";
        }
        cout << "|\n";
    }
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
void updateDomains(int2DMatrix &sudokuField, int3DMatrix &domainsMatrix, int row, int col)
{
    if (row == -1)
        return;
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
    int j;
    for (int i = blockRowStart; i < (blockRowStart + 3); i++)
    {
        for (j = blockColStart; j < (blockColStart + 3); j++)
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

/**
 * @brief The following function initializes a matrix big as the sudoku field, where every cell will be
 * filled with the domain of the same cell on the sudoku field.
 *
 * @param sudokuField
 * @param domainsMatrix
 */
void initializeDomainsMatrix(int2DMatrix &sudokuField, int3DMatrix &domainsMatrix)
{
    int j;
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (j = 0; j < FIELD_SIZE; j++)
        {
            if (sudokuField[i][j] != 0)
            {
                updateDomains(sudokuField, domainsMatrix, i, j);
            }
        }
    }
};

/**
 * @brief The following function is called by solveSudoku to perform a Forward checking based Constraint propagation to
 * solve the sudoku game: each time an empty cell is set, and all the domains of the matrix are updated, to check
 * if there is a constraint violation, and if a violation happens, the recursion reverts to the previous step.
 * The algorithm proceeds recursively at setting cells, until a solution is found.
 *
 * @param sudokuField
 * @param domainsMatrix
 * @param actRow
 * @param actCol
 * @return int2DMatrix
 */
int2DMatrix solveSudokuInternal(int2DMatrix sudokuField, int3DMatrix domainsMatrix, int actRow, int actCol)
{
    // Constraint propagation step
    updateDomains(sudokuField, domainsMatrix, actRow, actCol);

    int emptyCellRow, emptyCellColumn = -1;
    int2DMatrix result;

    int j;
    // Check if any constraint was violated, if not get the first empty cell to fill.
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (j = 0; j < FIELD_SIZE; j++)
        {
            if (sudokuField[i][j] == 0 && domainsMatrix[i][j].empty())
            {
                return {};
            }
            if (emptyCellColumn == -1 && sudokuField[i][j] == 0)
            {
                emptyCellRow = i;
                emptyCellColumn = j;
            }
        }
    }
    // Check if all the empty cells have been filled, and if so, return this field as result.
    if (emptyCellColumn == -1)
    {
        return sudokuField;
    }
    // Try to fill a cell.
    while (!domainsMatrix[emptyCellRow][emptyCellColumn].empty() && result.empty())
    {
        int2DMatrix nextStepField = sudokuField;
        nextStepField[emptyCellRow][emptyCellColumn] = domainsMatrix[emptyCellRow][emptyCellColumn][0];
        result = solveSudokuInternal(nextStepField, domainsMatrix, emptyCellRow, emptyCellColumn);
        if (result.empty())
        {
            domainsMatrix[emptyCellRow][emptyCellColumn].erase(domainsMatrix[emptyCellRow][emptyCellColumn].begin());
        }
    }
    return result;
}

/**
 * @brief The following function takes a sudoku field as input and returns the solved field (if existing).
 *
 * @param sudokuField
 * @return int2DMatrix
 */
int2DMatrix solveSudoku(int2DMatrix sudokuField)
{
    int3DMatrix domainsMatrix(FIELD_SIZE,
                              int2DMatrix(FIELD_SIZE,
                                          vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
    initializeDomainsMatrix(sudokuField, domainsMatrix);
    return solveSudokuInternal(sudokuField, domainsMatrix, -1, -1);
}