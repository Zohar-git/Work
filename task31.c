#include<stdio.h>
int power(double number,int hezka)
{
    if(hezka == 0)
    {
        return 1;
    }
    double sum = power(number,hezka -1);
    return sum * number ;
}
int main(void)
{
    double number = 0;
    int hezka = 0;
    printf("Enter the number :");
    scanf("%lf",&number);
    printf("Enter the hezka:");
    scanf("%d",&hezka);
    int y = power(number,hezka);
    printf("%d",y);
}