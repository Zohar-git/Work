#include<stdio.h>
void get_index_of_max(int *array, int size, int *max)
{
    printf("Enter numbers to the array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    *max = array[0];
    for (int b = 1; b < size; b++)
    {
        if (array[b]>= *max)
        {
            *max = array[b];
        }
    }
}
int main(void)
{
    int  size = 0,max =0;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int array [size];
    get_index_of_max(array,size,&max);
    printf("%d",max);
    return 0;
}