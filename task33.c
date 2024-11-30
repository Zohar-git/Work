#include<stdio.h>
int fib(int x)
{
    int a1 = 1,a2 =1;
    int number = 0;
    for (int i = 0; i < x-2; i++)
    {
        number = a2+a1;
        a1=a2;;
        a2 = number;   
    }
    return number;
}
int main(void)
{
    printf("Enter the location of the number:");
    int x = 0;
    scanf("%d",&x);
    int location = fib(x);
    printf("%d",location);
}