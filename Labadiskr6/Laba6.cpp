

#include "pch.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int GetFactorial(int n);
int GetСombination(int n, int k);
void GetBinomResult(int stepin);
void LeksDirection(int r, int n);


int main()
{
	int n, r;
	/*GetBinomResult(12);
	cout << "\n ----------------------------------------------------";*/
	cout << "Enter n\n";
	cin >> n;
	cout << "Enter r\n";
	cin >> r;
	LeksDirection(r, n);
}

int GetFactorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * GetFactorial(n - 1);
	}
}

int GetСombination(int n, int k)
{
	int result = (GetFactorial(n)) / (GetFactorial(n - k)*GetFactorial(k));
	return result;
}

void GetBinomResult(int stepin)
{

	int k = 0;
	string res;
	while (k <= stepin)
	{
		/*res+= GetСombination(stepin, k)*pow(x, (stepin - k))*pow((-y), k);*/
		if (pow((-1), k) == -1)
		{
			cout << pow((-1), k)*GetСombination(stepin, k) << "*x^" << stepin - k << "*y^" << k;
		}
		else
		{
			cout << "+" << pow((-1), k)*GetСombination(stepin, k) << "*x^" << stepin - k << "*y^" << k;
		}
		k++;
	}

}
//Задані додатні цілі числа n та r. Побудувати у лексикографічному порядку всі розміщення з повтореннями із r елементів множини {1, 2, …, n}.



void LeksDirection(int r, int n)
{

	int i = 1;
	vector<int> arrOfNumbers{1,2,3};
	vector<int> leks{};
	/*while (i <= n)
	{
		arrOfNumbers.push_back(i);
		i++;
	}*/
	int p; 
	for (int i = 0; i <= 333; i++)
	{
		p = i; int k = 0;
		while (p > 0)
		{
			leks.push_back(p % 10);
			p /= 10;
			k++;
		}
		int j = 0; int t = 0;

		for (int n = 0; n < k; n++)
		{
			for (int s = 0; s < arrOfNumbers.size(); s++)
			{
				if (leks[n] == arrOfNumbers[s])
				{
					++t;
					if (n == k - 1 && k == r && t == k)
					{
						cout << i;
						cout << "\n";
					}
					break;
				}
				else if (s == arrOfNumbers.size() - 1)
				{
					leks.clear();
					break;
				}
			}
		}

	}
}


















//
	//vector<int> bac;
	//vector<int>front;

	//while (number > 0)
	//{
	//	int digit = number % 10;
	//	number /= 10;
	//	bac.push_back(digit);
	//}
	//int i = 0;
	//reverse(bac.begin(), bac.end());
	//*/