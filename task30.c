#include <stdio.h>
#define SIZE_ARRAY 5
int search(int *array, int val_search)
{
    int mid = SIZE_ARRAY / 2;
    int left = array[0];
    int right = array[SIZE_ARRAY];
    while (array[mid] != val_search)
    {
        if (val_search < array[mid])
        {
            right = mid;
            mid /= 2;
        }
        else if ( val_search > array[mid])
        {
            left = mid;
            mid *= 1.5;
        }
        if (left > right || right > left)
        {
            return -1;
        }
    }
    return mid;
}
int main(void)
{
    int array[SIZE_ARRAY] = {0};
    for (int i = 0; i < SIZE_ARRAY; i++)
    {
        printf("Enter the %dst number:", i + 1);
        scanf("%d", &array[i]);
    }
    int val_search = 0;
    printf("Enter the val you want to check:");
    scanf("%d", &val_search);
    int place_val = search(array, val_search);
    printf(" %d is in the %d place in the array", val_search, place_val);
    return 0;
}