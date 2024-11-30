#include<stdio.h>
int main()
{
int number;
int a,b,c;
printf("Enter a 3 digit number:");
scanf("%d",&number);
a = number%10;
b = (number/10)%10;
c= number/100;
printf("The reversed number is :%d%d%d",a,b,c);
return 0;

















































}