#include <stdio.h>
int number;
void check_in_number()
{
    printf("Enter a positive number:");
    scanf("%d", &number);
}
void find_rishonim()
{
    int array[20] = {0};
    int x;
    for (x=2; x< 20; x++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (number % x == 0)
            {
                array[x]++;
                number /= x;
            }
            else
            {
                break;
            }
        }
    }
    for (int b = 2; b < 20; b++)
    {
        for (int z = 0; z < array[b]; z++)
        {
               printf("%d ", b);
        }
    }
}
int main(void)
{
    check_in_number();
    if (number < 0)
    {
        return 1;
    }
   find_rishonim();
    return 0;
}