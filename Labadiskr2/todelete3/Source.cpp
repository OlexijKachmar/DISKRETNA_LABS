


#include <stdio.h>
#include<iostream>//якшо юзер вводить однакові елементи для 1 масив - попросити щоб ввів різні.
int array1[5] = {};
int array2[3] = {};
int main()
{//вивести в метод.
    printf("Enter 5 elements of array1:\n");
	for(int i = 0;i < 5;i++)
	{
		scanf("%d",&array1[i]);
		
	}
	printf("Enter 3 elements of array2:\n");
	for(int j = 0;j <3; j++)
	{
		scanf("%d",&array2[j]);
		
	}
	
	int* intersection = new int[5]; 
	int p = 0 ;
	printf("Intersective elements:\n");
	for ( int i = 0; i<5; i++)
	{ 
	    for (int j = 0; j<3; j++)
	    {
	        if(array1[i] == array2[j])
	        {
				intersection[p]= array1[i];
				printf("%d\t",array1[i]);
				p++;
				break;
	        }
	    }
	}
	printf("\nPower of intersection is: %d\n",p);
	delete [] intersection;


	int t = 0;
	bool isElementPresent;
	int unionSet[5 + 3];
	for(int i =0; i<5; i++)
	{
		unionSet[i] = array1[i];
		printf("%d\n",array1[i]);
	}
	
	int k = 0;
	for(int i = 5 ; i<5+3 && k<3; i++)
	{
		 isElementPresent = false;
		for(int j = 0 ;j<5; j++)
		{
			if(unionSet[j]==array2[k])
		    {
				isElementPresent = true;
				break;
			}
		}
		
		if(isElementPresent == false)
		{
			unionSet[i] = array2[k];
			printf("%d\n",array2[k]);
		}
		else
		{
			i--;
			
		}
		k++;
		
	}
	printf("Union of elements:\n");
	system("pause");
	return 0;
}
