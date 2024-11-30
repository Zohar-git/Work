#include <stdio.h>
#include <stdbool.h>
int main()
{
    int amount_numbers;
    double y, avg, sum = 0;
    printf("Enter the amount of number you want to take avarage from:");
    scanf("%d", &amount_numbers);
    int x;
    // printf("Good,now enter the first number:");
    for (x = 0; x < amount_numbers; x++)
    {
        printf("Enter the %dst number : ", x + 1);
        scanf("%lf", &y);
        sum += y;
    }

    avg = sum / amount_numbers;
    printf("The avarage of the numbers is :%.2lf", avg);

    return 0;
}
