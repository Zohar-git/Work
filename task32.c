#include <stdio.h>
void print_reversed(int number)
{
    if (number == 0)
    {
        return;
    }
    int x = number%10;
    printf("%d", x);
    print_reversed(number / 10);
}
int main(void)
{
    int number = 0;
    int base = 1;
    printf("Enter the number and when you are enter '0':");
    scanf("%d", &number);
    print_reversed(number);
    return 0;
}