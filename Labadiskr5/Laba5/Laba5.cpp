// Laba5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> DeleteElement(vector<int> vector, int valueToDelete);
/*vector<vector<int>>*/
vector<vector<int>>  GetPath(int matrix[30][30], vector<int> points, vector<int> *weight, vector<int> usedPoints);
int ValidInput();

int main()
{

	int matrix[30][30];
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30;j++)
		{
			matrix[i][j] = 9999;
		}
	}
	matrix[0][1] = 6;
	matrix[0][6] = 3;
	matrix[1][0] = 6;
	matrix[1][2] = 7;
	matrix[1][7] = 2;
	matrix[2][1] = 7;
	matrix[2][3] = 1;
	matrix[2][8] = 3;
	matrix[3][2] = 1;
	matrix[3][4] = 4;
	matrix[3][9] = 1;
	matrix[4][3] = 4;
	matrix[4][5] = 1;
	matrix[4][10] = 7;
	matrix[5][4] = 1;
	matrix[5][11] = 5;
	matrix[6][0] = 3;
	matrix[6][7] = 8;
	matrix[6][12] = 7;
	matrix[7][1] = 2;
	matrix[7][6] = 8;
	matrix[7][8] = 1;
	matrix[7][13] = 3;
	matrix[8][2] = 3;
	matrix[8][7] = 1;
	matrix[8][9] = 8;
	matrix[8][14] = 4;
	matrix[9][3] = 1;
	matrix[9][8] = 8;
	matrix[9][10] = 2;
	matrix[9][15] = 5;
	matrix[10][4] = 7;
	matrix[10][9] = 2;
	matrix[10][11] = 1;
	matrix[10][16] = 4;
	matrix[11][5] = 5;
	matrix[11][10] = 1;
	matrix[11][17] = 7;
	matrix[12][6] = 7;
	matrix[12][13] = 1;
	matrix[12][18] = 3;
	matrix[13][7] = 3;
	matrix[13][12] = 1;
	matrix[13][14] = 3;
	matrix[13][19] = 2;
	matrix[14][8] = 4;
	matrix[14][13] = 3;
	matrix[14][15] = 3;
	matrix[14][20] = 1;
	matrix[15][9] = 5;
	matrix[15][14] = 3;
	matrix[15][16] = 4;
	matrix[15][21] = 3;
	matrix[16][10] = 4;
	matrix[16][15] = 4;
	matrix[16][17] = 2;
	matrix[16][22] = 4;
	matrix[17][11] = 7;
	matrix[17][16] = 2;
	matrix[17][23] = 5;
	matrix[18][12] = 3;
	matrix[18][19] = 7;
	matrix[18][24] = 1;
	matrix[19][13] = 2;
	matrix[19][18] = 7;
	matrix[19][20] = 1;
	matrix[19][25] = 7;
	matrix[20][14] = 1;
	matrix[20][19] = 1;
	matrix[20][21] = 5;
	matrix[20][26] = 3;
	matrix[21][15] = 3;
	matrix[21][20] = 5;
	matrix[21][22] = 3;
	matrix[21][27] = 8;
	matrix[22][16] = 4;
	matrix[22][21] = 3;
	matrix[22][23] = 8;
	matrix[22][28] = 1;
	matrix[23][17] = 5;
	matrix[23][22] = 8;
	matrix[23][29] = 7;
	matrix[24][18] = 1;
	matrix[24][25] = 4;
	matrix[25][19] = 7;
	matrix[25][24] = 4;
	matrix[25][26] = 2;
	matrix[26][20] = 3;
	matrix[26][25] = 2;
	matrix[26][27] = 3;
	matrix[27][21] = 8;
	matrix[27][26] = 3;
	matrix[27][28] = 7;
	matrix[28][22] = 1;
	matrix[28][27] = 7;
	matrix[28][29] = 6;
	matrix[29][22] = 7;
	matrix[29][28] = 6;
	

	

	int startPoint;
	int aimPoint;
	cout << "Enter element,u want to start with\n";
	startPoint = ValidInput();

	while(startPoint == 0)
	{
		cout << "startpoint !=<<startPoint";
		cin >> startPoint;
	}

	cout << "Enter aim point";
	cin >> aimPoint;
	vector<int> usedPoints;
	vector<int> unusedPoints{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	vector<int> weightOfVerticles{9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999,9999 };
	weightOfVerticles.at(startPoint - 1) = 0;
	unusedPoints = DeleteElement(unusedPoints, startPoint);
	usedPoints.push_back(startPoint);
	vector<vector<int>>result = GetPath(matrix, unusedPoints, &weightOfVerticles, usedPoints);
	/*int usedPointsSize = usedPoints.size();*/
	cout << weightOfVerticles.at(aimPoint - 1);
	/*for (int i = 0; i < usedPointsSize; i++)
	{
		cout << usedPoints[i];
		cout << ",";
	}

*/	vector<int> resultPath = result.at(aimPoint  - 1);
	resultPath.push_back(aimPoint);

	cout << "\nThe shortest way is: \t";
	for (int i = 0; i < resultPath.size(); i++)
	{
		cout << resultPath[i] << " ";
	}

}

vector<vector<int>>  GetPath(int matrix[30][30], vector<int> points, vector<int>* weight, vector<int> usedPoints)
{

	int minElement;


	int pointsSize = points.size();
	vector<vector<int>> path(pointsSize + 1);
	for (int i = 0; i < pointsSize; i++)
	{
		int previousVerticle = usedPoints[i];

		int min = 9999;

		for (int j = 0; j < points.size(); j++)
		{

			int currentVerticle = points[j];
			if (weight->at(currentVerticle - 1) > matrix[previousVerticle - 1][currentVerticle - 1] + weight->at(previousVerticle - 1))
			{
				weight->at(currentVerticle - 1) = matrix[previousVerticle - 1][currentVerticle - 1] + weight->at(previousVerticle - 1);

				vector<int> verticlePath = path.at(previousVerticle - 1);
				verticlePath.push_back(previousVerticle);
				path.at(currentVerticle - 1) = verticlePath;
			}
			if (weight->at(currentVerticle - 1) < min)//check
			{
				min = weight->at(currentVerticle - 1);
				minElement = points[j]; // or j here. need to check
			}
		}
		points = DeleteElement(points, minElement);
		usedPoints.push_back(minElement);
	}
	return path;
}

vector<int> DeleteElement(vector<int> vector, int valueToDelete)
{
	for (int i = 0;i < vector.size();i++)
	{
		if (vector.at(i) == valueToDelete)
		{
			vector.erase(vector.begin() + i);
		}
	}
	return vector;
}

int ValidInput()
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
