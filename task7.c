#include<stdio.h>
#define N 10
int main(void)
{
    int x;
    int array[N+1];
    printf("Enter 10 numbers:");
    for (int i = 0; i < N+1; i++)
    {
        scanf("%d",&x);
        array[i]=x;
    }
    for (int b = N+1; b>0 ; b--)
    {
        printf("%d ,",array[b-1]);
    }
    return 0;
}