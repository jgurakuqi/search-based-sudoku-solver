#define FIELD_SIZE 9

vector<vector<int>> solveSudoku(vector<vector<int>> sudokuField)
{
    if (sudokuField == nullptr)
    {
        return nullptr;
    }
    return solveSudokuI(sudokuField, createSudokuDomain(sudokuField));
}

vector<vector<int>> solveSudokuI(vector<vector<int>> sudokuField, vector<vector<vector<int>>> sudokuCellsDomains)
{
    // Constraint propagation step
    vector<vector<vector<int>>> sudokuCellsDomains = updateSudokuDomain(sudokuCellsDomains);
    int emptyCellRow, emptyCellColumn = -1;
    vector<vector<int>> result = nullptr;

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (sudokuField[i][j] == 0 && sudokuCellsDomains[i][j].empty())
            {
                return nullptr;
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
    while (!sudokuCellsDomains[emptyCellRow][emptyCellColumn].empty() && result != nullptr)
    {
        vector<vector<int>> nextStepField = sudokuField;
        nextStepField[i][j] = sudokuCellsDomains[i][j][0];
        result = solveSudokuI(nextStepField, sudokuCellsDomains);
        if (result == nullptr)
        {
            sudokuCellsDomains[emptyCellRow][emptyCellColumn].remove(0);
        }
    }
    return result;
}