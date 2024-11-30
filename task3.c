#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i,b;
    printf("Enter the amount of numbers in the series:");
    scanf("%d",&i);
    double mynumbers[i];
    printf("Enter the series on numbers:");
    for (b=0; b<i ;b++)
    {
        scanf("%lf",&mynumbers[b]);
       }
       double min = mynumbers[0];
       double max = mynumbers[0];

       for (b = 0; b < i; b++)
       {
           if (mynumbers[b] >max)
           {
               max = mynumbers[b];
           }
            if (mynumbers[b] < min)
            {
                min = mynumbers[b];
            }
            }
             printf("The max number in the series is %lf\n", max);
               printf("The min number in the series is %lf", min);
               return 0;
           }