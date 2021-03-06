// Laba4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

double ValidInput();
vector<int> DeleteElement(vector<int> vector, int valueToDelete);
int main()
{
	int matrix[11][11];
	matrix[0][0] = INT_MAX;
	matrix[0][1] = 1;
	matrix[0][2] = 2;
	matrix[0][3] = 4;
	matrix[0][5] = INT_MAX;
	matrix[0][6] = INT_MAX;
	matrix[0][7] = INT_MAX;
	matrix[0][8] = INT_MAX;
	matrix[0][9] = INT_MAX;
	matrix[0][10] = INT_MAX;
	matrix[1][0] = 1;
	matrix[1][1] = INT_MAX;
	matrix[1][2] = INT_MAX;
	matrix[1][3] = INT_MAX;
	matrix[1][4] = 3;
	matrix[1][5] = INT_MAX;
	matrix[1][6] = 2;
	matrix[1][7] = INT_MAX;
	matrix[1][8] = INT_MAX;
	matrix[1][9] = INT_MAX;
	matrix[1][10] = INT_MAX;
	matrix[2][0] = 2;
	matrix[2][1] = INT_MAX;
	matrix[2][2] = INT_MAX;
	matrix[2][3] = INT_MAX;
	matrix[2][4] = 7;
	matrix[2][5] = 5;
	matrix[2][6] = INT_MAX;
	matrix[2][7] = INT_MAX;
	matrix[2][8] = INT_MAX;
	matrix[2][9] = INT_MAX;
	matrix[2][10] = INT_MAX;
	matrix[3][0] = 4;
	matrix[3][1] = INT_MAX;
	matrix[3][2] = INT_MAX;
	matrix[3][3] = INT_MAX;
	matrix[3][4] = INT_MAX;
	matrix[3][5] = 2;
	matrix[3][6] = 3;
	matrix[3][7] = INT_MAX;
	matrix[3][8] = INT_MAX;
	matrix[3][9] = INT_MAX;
	matrix[3][10] = INT_MAX;
	matrix[4][0] = INT_MAX;
	matrix[4][1] = 3;
	matrix[4][2] = 7;
	matrix[4][3] = INT_MAX;
	matrix[4][4] = INT_MAX;
	matrix[4][5] = INT_MAX;
	matrix[4][6] = INT_MAX;
	matrix[4][7] = 4;
	matrix[4][8] = 6;
	matrix[4][9] = INT_MAX;
	matrix[4][10] = INT_MAX;
	matrix[5][0] = INT_MAX;
	matrix[5][1] = INT_MAX;
	matrix[5][2] = 5;
	matrix[5][3] = 2;
	matrix[5][4] = INT_MAX;
	matrix[5][5] = INT_MAX;
	matrix[5][6] = INT_MAX;
	matrix[5][7] = 7;
	matrix[5][8] = INT_MAX;
	matrix[5][9] = 3;
	matrix[5][10] = INT_MAX;
	matrix[6][0] = INT_MAX;
	matrix[6][1] = 2;
	matrix[6][2] = INT_MAX;
	matrix[6][3] = 3;
	matrix[6][4] = INT_MAX;
	matrix[6][5] = INT_MAX;
	matrix[6][6] = INT_MAX;
	matrix[6][7] = INT_MAX;
	matrix[6][8] = 5;
	matrix[6][9] = 7;
	matrix[6][10] = INT_MAX;
	matrix[7][0] = INT_MAX;
	matrix[7][1] = INT_MAX;
	matrix[7][2] = INT_MAX;
	matrix[7][3] = INT_MAX;
	matrix[7][4] = 4;
	matrix[7][5] = 7;
	matrix[7][6] = INT_MAX;
	matrix[7][7] = INT_MAX;
	matrix[7][8] = INT_MAX;
	matrix[7][9] = INT_MAX;
	matrix[7][10] = 4;
	matrix[8][0] = INT_MAX;
	matrix[8][1] = INT_MAX;
	matrix[8][2] = INT_MAX;
	matrix[8][3] = INT_MAX;
	matrix[8][4] = 6;
	matrix[8][5] = INT_MAX;
	matrix[8][6] = 5;
	matrix[8][7] = INT_MAX;
	matrix[8][8] = INT_MAX;
	matrix[8][9] = INT_MAX;
	matrix[8][10] = 1;
	matrix[9][0] = INT_MAX;
	matrix[9][1] = INT_MAX;
	matrix[9][2] = INT_MAX;
	matrix[9][3] = INT_MAX;
	matrix[9][4] = INT_MAX;
	matrix[9][5] = 3;
	matrix[9][6] = 7;
	matrix[9][7] = INT_MAX;
	matrix[9][8] = INT_MAX;
	matrix[9][9] = INT_MAX;
	matrix[9][10] = 4;
	matrix[10][0] = INT_MAX;
	matrix[10][1] = INT_MAX;
	matrix[10][2] = INT_MAX;
	matrix[10][3] = INT_MAX;
	matrix[10][4] = INT_MAX;
	matrix[10][5] = INT_MAX;
	matrix[10][6] = INT_MAX;
	matrix[10][7] = 4;
	matrix[10][8] = 1;
	matrix[10][9] = 4;
	matrix[10][10] = INT_MAX;

	cout << "Enter element,you want to start with\n";
	double element = ValidInput();
	vector<int> usedPoints;
	vector<int> unusedPoints{ 1,2,3,4,5,6,7,8,9,10,11 };
	double i = 0;
	do
	{
		if (i == 10 && unusedPoints.at(i)!= element)
		{
			cout << "Bad entry\n";
			element = ValidInput();
			i = 0;
		}
		else if(unusedPoints.at(i) == element)
		{
			break;
		}
		i++;
	} while (i != 11);
	
	usedPoints.push_back(element);
	unusedPoints = DeleteElement(unusedPoints, element);
	while (unusedPoints.size() != 0)
	{
		int min = INT_MAX;
		int usedPoint;
		int valueToPush;
		for (int i = 0; i < unusedPoints.size(); i++)
		{
			for (int j = 0; j < usedPoints.size(); j++)
			{
				if (min > matrix[unusedPoints[i] - 1][usedPoints[j] - 1])
				{
					min = matrix[unusedPoints[i] - 1][usedPoints[j] - 1];
					valueToPush = unusedPoints[i];
					usedPoint = usedPoints[j];
				}
			}
		}
		cout << usedPoint << "->" << valueToPush << ";\t";
		usedPoints.push_back(valueToPush);
		unusedPoints = DeleteElement(unusedPoints, valueToPush);
	}
}



vector<int> DeleteElement(vector<int> vector, int valueToDelete)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector.at(i) == valueToDelete)
		{
			vector.erase(vector.begin() + i);
		}
	}
	return vector;
}

double ValidInput()
{
	double x;
	cin >> x;
	while (std::cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Bad entry. \n";
		cin >> x;
	}
	
	return x;
}



