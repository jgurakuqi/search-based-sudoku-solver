#include <iostream>
#include <vector>
#include <iterator>
#define FIELD_SIZE 9

using namespace std;

/**
 * @brief This function initializes the matrix using '.' as 
 * representation of an empty cell.
 * 
 * @param sudokuField 
 */
void createEmptyMatrix(vector<vector<char>>& sudokuField)
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		vector<char> row;
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			row.push_back('.');
		}
		sudokuField.push_back(row);
	}
}

/**
 * @brief This method prints the content of the vector values.
 * 
 * @tparam T 
 * @param stream 
 * @param values 
 * @return ostream& 
 */
template<class T>
ostream& operator<<(ostream& stream, const std::vector<T>& values)
{
	for (auto &value : values)
	{
		stream << value << " ";
	}
    stream << '\n';
    return stream;
}



int main()
{
	vector<vector<char>> sudokuField;
	createEmptyMatrix(sudokuField);
	cout << sudokuField;
	return 0;
}
