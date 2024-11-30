#include <stdio.h>
int Numberofzeros(int x)
{
    int amount_zeros = 0;
    while (x > 0)
    {
        if (x % 10 == 0)
        {
            amount_zeros++;
        }
        x /= 10;
    }
    return amount_zeros;
}
int main(void)
{
    while (1)
    {
        int number_user;
        printf("Enter any number:");
        scanf("%d", &number_user);
        int amount_zeros = Numberofzeros(number_user);
        printf("The amount of zeros in the number you enter is: %d\n",amount_zeros);
        if (amount_zeros == 0)
        {
            break;
        }
    }

    return 0;
}