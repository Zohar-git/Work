#include<stdio.h>
void swap (double *a, double *b)
{
double temp;
temp = *a;
*a = *b;
*b = temp;
}
int main(void)
{
    double a = 5.5 , b =7.2;
    swap(&a,&b);
    printf("a = %.2lf b = %.2lf",a,b);
    
    return 0;
}