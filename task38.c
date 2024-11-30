#include<stdio.h>
#include<stdlib.h>
int max (int *array,int size_array)
{
    if(size_array == 1)
    {
        return 0;
    }
    int index = max(array,size_array-1);
    if (array[index]<array[size_array-1])
    {
        return size_array-1;
    }
    else{return index;}
}
int main(void)
{
    int size,x=0;
    printf("Enter the amount of num is the array:");
    scanf("%d",&size);
    int *array = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dst number",i+1);
        scanf("%d",&x);
        array[i] = x;
    }
    int y = max(array,size);
    printf("%d",y+1);
    free(array);
    return 0;
}