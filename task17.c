#include <stdio.h>
int get_number(int number)
{
    number = 0;
    printf("Enter a positive number:");
    scanf("%d", &number);
    return number;
}
int fibonachi(int n)
{
    int sum=0;
    int array[100] = {0};
    array[0] = 1, array[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        array[i] = array[i - 2] + array[i - 1];
        sum += array[i];
    }
    printf("%d", array[n]);
}
int main(void)
{
    int number = get_number(0);
    if (number < 0)
    {
        printf("Its not positive number :(");
        return 1;
    }
    fibonachi(number);
    return 0;
}