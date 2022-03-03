#include <algorithm>
#include <vector>
#include <iterator>
#define FIELD_SIZE 9

using namespace std;

/**
 * @brief The following function performs the constraint propagation over the column, row and block related
 * to the cell [row][col], removing it's value from any domain
 *
 * @param sudokuField
 * @param domainsMatrix
 * @param row
 * @param col
 */
void updateDomainsX(vector<vector<int>> &sudokuField, vector<vector<vector<int>>> &domainsMatrix, int row, int col)
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

vector<vector<int>> solveSudokuI(vector<vector<int>> sudokuField, vector<vector<vector<int>>> domainsMatrix, int actRow, int actCol)
{
    // Constraint propagation step
    updateDomainsX(sudokuField, domainsMatrix, actRow, actCol);
    int emptyCellRow, emptyCellColumn = -1;
    vector<vector<int>> result;

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < FIELD_SIZE; j++)
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
    // Potresti fare differentemente il controllo, per vedere prima se la matrice e' gia completa.
    if (emptyCellColumn == -1)
    {
        return sudokuField;
    }
    while (!domainsMatrix[emptyCellRow][emptyCellColumn].empty() && result.empty())
    {
        vector<vector<int>> nextStepField = sudokuField;
        nextStepField[emptyCellRow][emptyCellColumn] = domainsMatrix[emptyCellRow][emptyCellColumn][0];
        result = solveSudokuI(nextStepField, domainsMatrix, emptyCellRow, emptyCellColumn);
        if (result.empty())
        {
            domainsMatrix[emptyCellRow][emptyCellColumn].erase(domainsMatrix[emptyCellRow][emptyCellColumn].begin());
        }
    }
    return result;
}

vector<vector<int>> solveSudoku(vector<vector<int>> sudokuField, vector<vector<vector<int>>> domainsMatrix)
{
    //@TODO: METTERE QUI LA CREAZIONE DELLA DOMAIN MATRIX.
    // if (sudokuField == nullptr)
    // {
    //     return nullptr;
    // }
    return solveSudokuI(sudokuField, domainsMatrix, -1, -1);
}