#include<stdio.h>

void addition(int a, int b)
{
	int c;

	c = a + b;

	printf("%d", c);

}

void subtraction(int a, int b)
{
	int c;

	c = a + b;

	printf("%d", c);

}

void multiplication(int a, int b)
{
	int c;

	c = a * b;

	printf("%d", c);

}

int main()
{
	addition(3, 5);
	subtraction(7, 3);
	multiplication(2, 4);
}
