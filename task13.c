#include <stdio.h>
#define SIZE_ARRAY 50
int main(void)
{
    int number[SIZE_ARRAY] = {0};
    printf("Enter numbers and if you want to end it enter 0:");
    int x, y = 0;
    for (int i = 0; i < SIZE_ARRAY; i++)
    {
        y = i;
        scanf(" %d", &x);
        number[i] = x;
        if (x == 0)
        {
            break;
        }
    }
    int y2 = y - 5;
    for (y2; y2 < y; y2++)
    {
        printf("%d ", number[y2]);
    }

    return 0;
}