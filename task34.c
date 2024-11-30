#include <stdio.h>
int sum_numbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum_numbers(n - 1);
}
int main(void)
{
    int n = 2;
    while (n > 1)
    {
        printf("Enter the number:");
        scanf("%d", &n);
        int y = sum_numbers(n);
        printf("%d \n", y);
    }
    return 0;
}