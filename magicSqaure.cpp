/*
 CS 1347 Summer 2020

 @Author: Nicholas Garcia

 I started with example 8-11 in the Malik textbook
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int NUMBER_OF_ROWS = 3;
const int NUMBER_OF_COLUMNS = 3;
const int MAGIC_NUMBER = 9;

void printMatrix(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS);

bool isMagic(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS);

void fillMatrix(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS);

void intializeMatrix(int matricx[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS); //fills matrix with -1 value

int main()
{
	int magicSqaure[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	//run loop here
	int count = 0;
	int timeRepeated;

	cout << "How many time would you like to test the magic sqaure";
	cin >> timeRepeated;
	cout << endl;

	for (int i = 0; i < timeRepeated; i++)
	{
		fillMatrix(matrix[][NUMBER_OF_COLUMNS], NUMBER_OF_ROWS);
	}
	if (isMagic(magicSqaure, NUMBER_OF_ROWS))
	{
		printMatrix(magicSqaure);
		count++;
	}

	return 0;

}

void printMatrix(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS)

{
	

	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
			cout << setw(5) << matrix[row][col] << " ";

		cout << endl;
	}
}

void intializeMatrix(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS)
{
	int row, col;

	for (row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (col = 0; col < NUMBER_OF_COLUMNS; col++){
			matrix[row][col] = -1;
		}

	}
}

void fillMatrix(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS)

{
	intializeMatrix(matrix[][NUMBER_OF_COLUMNS], NUMBER_OF_ROWS);

	//loop from 1-9
	// do while loop
	int i = 1;
	do {
		cout << i << " ";
	}
	while (i <= 9);

	float Row_Position = rand() 3%; // range from 0-2 
	float Col_Position = rand() 3%; // range from 0-2 
	//http://www.cplusplus.com/reference/cstdlib/rand/  , july 12th, 2020

	//if position is -1, replace with loop variable, increment loop variable
	//else generate new postion
	if (matrix[Row_Position][Col_Position] == -1) {
		for (i = 1; i <= 9; i++)
			Row_Position = rand() 3%; // range from 0-2 
	        Col_Position = rand() 3%; // range from 0-2 

	}
	else {
		cout << setw(5) << matrix[row][col] << " ";

	}

}

bool isMagic(int matrix[][NUMBER_OF_COLUMNS], int NUMBER_OF_ROWS)
{
	//https://stackoverflow.com/questions/29957506/magic-square-code
	int num;
	int sum = 0;

	bool magic = true;

	for (int i = 0; i < NUMBER_OF_ROWS; i++)
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			sum = sum + matrix[i][j];

	num = sum / NUMBER_OF_ROWS;

	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		sum = 0;

		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			sum = sum + matrix[i][j];

		if (sum != num)
		{
			magic = false;
			break;
		}
	}

	if (magic)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			sum = 0;

			for (int i = 0; i < NUMBER_OF_ROWS; i++)
				sum = sum + matrix[i][j];

			if (sum != num)
			{
				magic = false;
				break;
			}
		}
	}

	if (magic)
	{
		sum = 0;

		for (int i = 0; i < NUMBER_OF_ROWS; i++)
			sum = sum + matrix[i][i];

		magic = false;
	}

	if (magic)
	{
		sum = 0;

		for (int i = 0; i < NUMBER_OF_ROWS; i++)
			sum = sum + matrix[i][NUMBER_OF_ROWS - 1 - i];

		magic = false;
	}	

	return magic;
}






