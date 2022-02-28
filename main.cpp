#include <iostream>
#include <vector>


using namespace std;


int main()
{
	vector<vector<char>> sudokuField(9);
	const int FIELD_SIZE = 9;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; i++)
		{
			sudokuField[i].push_back(".");
		}
	}
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; i++)
		{
			cout << sudokuField[i][j] << " ";
		}
		cout << "\n"; 
	}
	return 0;
}
