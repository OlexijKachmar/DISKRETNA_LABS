


#include <stdio.h>
#include<iostream>//якшо юзер вводить однакові елементи для 1 масив - попросити щоб ввів різні.
int validInput();

int array1[5] = {};
int array2[3] = {};
int main()
{//вивести в метод.
	printf("Enter 5 elements of array1:\n");
	for (int i = 0; i < 5; i++)
	{
		array1[i] = validInput();
		

	}
	printf("Enter 3 elements of array2:\n");
	for (int j = 0; j < 3; j++)
	{
		array2[j] = validInput();

	}

	int* intersection = new int[5];
	int p = 0;
	printf("Intersective elements:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array1[i] == array2[j])
			{
				intersection[p] = array1[i];
				printf("%d\t", array1[i]);
				p++;
				break;
			}
		}
	}
	printf("\nPower of intersection is: %d\n", p);
	delete[] intersection;

	printf("Union of elements:\n");
	int powerOfUnion = 0;
	int t = 0;
	bool isElementPresent;
	int unionSet[5 + 3];
	for (int i = 0; i < 5; i++)
	{
		unionSet[i] = array1[i];
		printf("%d\n", array1[i]);
		powerOfUnion++;
	}

	int k = 0;
	for (int i = 5; i < 5 + 3 && k < 3; i++)
	{
		isElementPresent = false;
		for (int j = 0; j < 5; j++)
		{
			if (unionSet[j] == array2[k])
			{
				isElementPresent = true;
				break;
			}
		}

		if (isElementPresent == false)
		{
			unionSet[i] = array2[k];
			printf("%d\n", array2[k]);
			powerOfUnion++;
		}
		else
		{
			i--;

		}
		k++;

	}
	printf("Power of Union is %d\n", powerOfUnion);
	system("pause");
	return 0;
}
	int validInput()
	{
		int x;
		std::cin >> x;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Bad entry.  Enter a NUMBER: \n";
			std::cin >> x;
		}
		return x;
	}
	

