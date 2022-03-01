#include <iostream>
#include <vector>
#define FIELD_SIZE 9

using namespace std;

void createEmptyMatrix()
{

}

template<class T>
ostream& operator<<(ostream& stream, const std::vector<T>& values)
{
    copy( begin(values), end(values), ostream_iterator<T>(stream, " ") );
    stream << '\n';
    return stream;
}


int main()
{
	cout << " CHECK -1 ";
	vector<vector<char>> sudokuField;
	cout << " CHECK 0 ";
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		vector<char> row;
		cout << " CHECK 0 - 1 ";
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			row.push_back('.');
		}
		sudokuField.push_back(row);
	}
	cout << " CHECK 1 ";
	cout << sudokuField;
	// for (int i = 0; i < FIELD_SIZE; i++)
	// {
	// 	for (int j = 0; j < FIELD_SIZE; j++)
	// 	{
	// 		cout << sudokuField[i][j] << " ";
	// 	}
	// 	cout << "\n"; 
	// }
	return 0;
}
