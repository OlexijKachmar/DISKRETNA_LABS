// Laba4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> DeleteElement(vector<int> vector, int valueToDelete);
void GetMinWeight(int numberOfmatrix, int **matrix, int i);
void TableOfIncidence(int** matrix, int numberOfmatrix);
int main()
{
	int numberOfPointsInMatrix = 3;
	/*cout << "Enter how many matrix presents in your graph";
	cin >> numberOfmatrix;*/
	int **matrix;
	matrix = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int[3];
	}
	//TableOfIncidence(matrix, numberOfmatrix);

	matrix[0][0] = INT_MAX;
	matrix[0][1] = 4;
	matrix[0][2] = 6;
	matrix[1][0] = 4;
	matrix[1][1] = INT_MAX;
	matrix[1][2] = 5;
	matrix[2][0] = 6;
	matrix[2][1] = 5;
	matrix[2][2] = INT_MAX;
	vector<int> usedPoint;
	vector<int> unusedPoint{ 1,2,3 };

	usedPoint.push_back(1);
	unusedPoint = DeleteElement(unusedPoint, 1);
	/*
	unusedPoint.erase(unusedPoint.begin() + 1);*/
	
	while (unusedPoint.size() != 0)
	{
		int min = INT_MAX;
		int valueToPush;
		for (int i = 0; i < unusedPoint.size(); i++)
		{
			for (int j = 0; j < usedPoint.size(); j++)
			{
				if (min > matrix[i][j])
				{
					min = matrix[i][j];
					valueToPush = i + 1;
				}
			}
		}
		usedPoint.push_back(valueToPush);
		unusedPoint = DeleteElement(unusedPoint, valueToPush);
	}

	for (int i = 0; i < usedPoint.size(); i++)
	{
		cout << usedPoint.at(i);
	}
}

vector<int> DeleteElement(vector<int> vector,int valueToDelete)
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

void GetMinWeight(int numberOfmatrix, int **matrix, int i)
{
	int min = INT_MAX;
	for (int j = 0; j < numberOfmatrix; j++)
	{
		if (matrix[i][j] < min)
		{
			min = matrix[i][j];
		}
	}
}
void TableOfIncidence(int** matrix, int numberOfmatrix)
{
	cout << "Enter a table of incidence";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = INT_MAX;
			}
		}
		cout << "\n";
	}
}
