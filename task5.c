#include<stdio.h>
int main(void)
{
int size=0;
printf("Enter a number between 1-26:");
scanf("%d",&size);
if(size<=0 || size>26)
{
printf("size input error");
return 1;
}
int a,b,i;
char character = 'A';

for (a=0 ; a <size; a++)
{
    for (b=0; b<size; b++)
    {
        printf("%c",character);
    }
    printf("\n");
    for (i = 0; i <= a; i++)
    {
        printf(" ");
    }
    character++;
}
return 0;









































}