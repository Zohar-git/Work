#include <stdio.h>
int digits_are_different(int x)
{
    int number[10] = {0};
    while (x > 0)
    {

        int digit = x % 10;
        number[digit]++;
        x/=10;
        if (number[digit] == 2)
        {
            printf("Not all the digits are uniqe\n");
            return 0;
            break;
        }
    }
    return 1;
}
int main(void)
{
    int amount_of_numbers = 0;
    while (1)
    {
        int x;
        printf("Enter a number:");
        scanf("%d", &x);
        if (digits_are_different(x) == 1)
        {
            printf("All the digits in this number are uniqe\n");
            printf("Before this number you enterd %d number that not all their digits are unique.", amount_of_numbers);
            break;
        }
        else
        {
            amount_of_numbers++;
        }
    }
    return 0;
}