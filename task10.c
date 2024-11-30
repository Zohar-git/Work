#include<stdio.h>
#define AMOUNTGRADES 10
#define MAX 100
#define MIN 0
int main(void)
{
int x ;
int Grades[MAX+1]={0};
printf("Enter 10 Grades:");
for (int i = 0; i < AMOUNTGRADES; i++)
{
    scanf("%d",&x);
    if (x<MIN || x>MAX)
    {
        continue;
    }
    
    Grades[x]++;
}
for (int z = 0; z < MAX+1; z++)
{
    if(Grades[z]>0)
    {
        printf("%d appears %d times\n",z,Grades[z]);
    }
}
return 0;
}