

//#include "pch.h"
//#include <iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//int GetFactorial(int n);
//int GetСombination(int n, int k);
//void GetBinomResult(int stepin);
//void LeksDirection(int r, int n);
//
//
//int main()
//{
//	int n, r;
//	/*GetBinomResult(12);
//	cout << "\n ----------------------------------------------------";*/
//	cout << "Enter n\n";
//	cin >> n;
//	cout << "Enter r\n";
//	cin >> r;
//	LeksDirection(r, n);
//}
//

//Задані додатні цілі числа n та r. Побудувати у лексикографічному порядку всі розміщення з повтореннями із r елементів множини {1, 2, …, n}.



//void LeksDirection(int r, int n)
//{
//	int ch = pow(10, r-1);
//	int i = 1;
//	vector<int> leks;
//	vector <int> arrOfNumbers;
//	while (i <= n)
//	{
//		arrOfNumbers.push_back(i);
//		i++;
//	}
//	int p; 
//	while (ch != pow(10, r ))
//	{
//		 int amountOfNumbers = 0;
//		while (ch > 0)
//		{
//			leks.push_back(ch % 10);
//			ch /= 10;
//			amountOfNumbers++;
//		}
//		 int t = 0;
//		for (int n = 0; n < amountOfNumbers; n++)
//		{
//			for (int s = 0; s < arrOfNumbers.size(); s++)
//			{
//				if (leks[n] == arrOfNumbers[s])
//				{
//					++t;
//					if (n == amountOfNumbers - 1 && amountOfNumbers == r && t == amountOfNumbers)
//					{
//						cout << ch;
//						cout << "\n";
//					}
//					break;
//				}
//				else if (s == arrOfNumbers.size() - 1)
//				{
//					leks.clear();
//					break;
//				}
//				s = 0;
//			}
//		}
//		leks.clear();
//		ch++;
//
//	}
//}

#include"pch.h"
using namespace std;

int GetFactorial(int n);
int GetСombination(int n, int k);
void GetBinomResult(int stepin);
void LexDirection(size_t size, size_t r);
int ValidInput();

void LexDirection(size_t size, size_t r)
{
	int bord = pow(size, r);
	vector <string> result;

	for (size_t i = 0; i < bord; i++)
	{
		result.push_back("");
		for (size_t j = 0; j < r; j++) //конкатенація символів елементів розміщень
		{
			result[i] += '0' + (((int)(i / pow(size, r - j - 1))) % size + 1);
		}
	}

	for (size_t i = 0; i < bord; i++)
	{
		cout << result[i] << endl;
	}
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

int main()
{
	size_t n;
	size_t r;
	cout << "Enter n: ";
	n = ValidInput();
	cout << "Enter r: ";
	r = ValidInput();
	LexDirection(n, r);
	cout << "--------------------------------------\n";
	GetBinomResult(12);
	system("pause");
	return 0;
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