#include<stdio.h>

int array[5] = { 0 };

int main()
{
	for (int a = 0; a < 5; a++)
	{
		array[a] = a;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d \n", array[i]);
	}

}
