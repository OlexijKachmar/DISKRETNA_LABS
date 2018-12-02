// Laba5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> DeleteElement(vector<int> vector,int valueToDelete);
vector<vector<int>> GetPath(int matrix[6][6], vector<int> points, vector<int> weight, vector<int> usedPoints);

int main()
{
  
	int matrix[6][6];
	int startPoint;int aimPoint;
	cout << "Enter element,u want to start with\n";
	cin >> startPoint;
	vector<int> usedPoints;
	vector<int> unusedPoints{ 1,2,3,4,5,6 };
	vector<int> weightOfVerticles{ INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX };
	weightOfVerticles.at(startPoint - 1) = 0;
	unusedPoints = DeleteElement(unusedPoints, startPoint);
	
	usedPoints.push_back(startPoint);
	GetPath(matrix, unusedPoints, weightOfVerticles, usedPoints);
	int usedPointsSize = usedPoints.size();
	for (int i = 0; i < usedPointsSize; i++)
	{
		cout << usedPoints[i];
		cout << ",";
	}

		
}

vector<vector<int>> GetPath(int matrix[6][6], vector<int> points, vector<int> weight, vector<int> usedPoints)
{
	
	int minElement;
	int pointsSize = points.size();
	vector<vector<int>> path(pointsSize);
	for (int i = 0; i < pointsSize; i++)
	{
		int min = INT_MAX;
		int previousVerticle = usedPoints[i];
		for (int j = 0; j < pointsSize; j++)
		{
			int currentVerticle = points[j];
			if (weight.at(currentVerticle - 1) > matrix[previousVerticle - 1][currentVerticle - 1] + weight.at(previousVerticle - 1))
			{
				weight.at(currentVerticle - 1) = matrix[previousVerticle - 1][currentVerticle - 1] + weight.at(previousVerticle - 1);

				vector<int> verticlePath = path.at(previousVerticle - 1);
				verticlePath.push_back(previousVerticle);
				path.at(currentVerticle - 1) = verticlePath;
			}
			if (weight.at(previousVerticle - 1) < min)//check
			{
				min = weight.at(currentVerticle - 1);
				minElement = points.at(previousVerticle - 1); // or j here. need to check
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
		if(vector.at(i)== valueToDelete)
		{
			vector.erase(vector.begin() + i);
		}
	}
	return vector;
}
