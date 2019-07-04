#include<stdio.h>

int addition(int a, int b)
{
	int c;

	c = a + b;

	return c;

}

int main()
{
	int answer;
	answer = addition(5, 7);

	printf("%d", answer);

}