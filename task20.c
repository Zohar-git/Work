#include <stdio.h>
void print_set(int *array, int size)
{
    printf("Enter numbers to the array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i]== -1)
        {
            continue;
        }
        
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                array[j] = -1;
            }
        }
    }

}
    int main(void)
    {
        int size = 0;
        printf("Enter the size of the array:");
        scanf("%d", &size);
        int array[size];
        if (size <= 0)
        {
            return 1;
        }
        print_set(array, size);
        for (int i = 0; i < size; i++)
        {
            if (array[i] != -1)
            {
                printf("%d ", array[i]);
            }
        }
        return 0;
    }