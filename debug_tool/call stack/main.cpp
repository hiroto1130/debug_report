#include<stdio.h>

void addition(int a, int b)
{
	int c;

	c = a + b;

	printf("%2d + %d = %d \n", a, b, c);
}

void subtraction(int a, int b)
{
	int c;

	c = a - b;

	printf("%2d - %d = %d \n", a, b, c);
}

void multiplication(int a, int b)
{
	int c;

	c = a * b;

	printf("%2d * %d =%d \n", a, b, c);
}

int main()
{
	addition(7,5);
	subtraction(10,3);
	multiplication(2,5);

	return 0;
}