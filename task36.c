#include<stdio.h>
void list_up(int number)
{
    if (number==0)
    {
        return;
    }
    list_up(number -1);
    printf("%d ", number);
}
int main(void)
{
    int number;
    printf("Enter the number:");
    scanf("%d",&number);
    list_up(number);
    return 0;
}