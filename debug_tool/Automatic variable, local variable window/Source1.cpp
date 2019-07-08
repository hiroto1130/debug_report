#include <stdio.h>

int add(int a, int b)
{
	int c;
	c = a + b;

	return c;

}

int main()
{
	int HP = 100;
	int MP = 50;
	const char *name = "mono";
	int answer;
	answer = add(5, 7);


	printf(" 体力：%2d \n 魔法力：%2d \n 名前：%2s \n", HP, MP, name);
	printf("足し算結果：%d \n", answer);
}