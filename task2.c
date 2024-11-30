#include<stdio.h>
int main(void)
{
    int b,a;
    int x;
    printf("Enter a number bigger than 0:");
    scanf("%d",&b);
    for ( a = 1; a <= b; b--)
    { 
        for (x = 0; x <b; x++)
        {
            printf("*");
        }
        printf("\n");
    }
    
     }