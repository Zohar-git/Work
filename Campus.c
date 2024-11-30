#include <stdio.h>

int main(void)
{
	int x,y,z;
	x = 2;
	y=x--;
	z=--x;
	printf("The value of x is:%d\n",x);
	printf("The value of y is:%d\n",y);
	printf("The value of z is:%d\n",z);
}