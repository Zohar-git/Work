#include<stdio.h>
#define N 10
#define MAX 9
int main(void)
{
int x=0;
int array[N] = {0};
printf("Enter 10 numbers for 0-9:");
for (int i = 0; i < N; i++)
{
    scanf("%d",&x);
    array[x]++;
}
for ( int a = 0; a < N; a++)
{
    if (array[a]>0)
    {
     printf("%d",a);   
    }
    
}







return 0; 
}