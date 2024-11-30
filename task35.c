#include<stdio.h>
int power_calc(int number,int power)
{
    if (power ==1)
    {
        return number;
    }
    return number*(power_calc(number,power-1));
}
int main(void)
{
    int number,power; 
    printf("Enter the number:");
    scanf("%d",&number);
    printf("Enter the power:");
    scanf("%d",&power);
    int y = power_calc(number,power);
    printf("%d^%d = %d",number,power,y);
    return 0 ;
}
