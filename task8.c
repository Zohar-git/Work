#include<stdio.h>
#include<string.h>
int main(void)
{
    int length1,length2;
    printf("Enter the length of the first array:");
    scanf("%d",&length1);
    printf("Enter the length of the second array:");
    scanf("%d", &length2);

    char array1[length1];
    char array2[length2];
    char x1,z2;
    printf("Write some words:");
    for (int i = 0; i < length1; i++)
    {
        scanf(" %c",&array1[i]);
    }
    printf("Write some more words:");
    for (int b = 0; b<length2;b++)
    {
        scanf(" %c",&array2[b]);
    }
    int loop_end=0,correct=0,y=0;
    end:
    for ( y;y < length1; y++)
    {
        loop_end = y;
        if (array1[y]==array2[0])
        {
            break;
        }
    }
    for ( int z = 0; z < length2; z++,loop_end++)
    {   
        if (array1[loop_end]=array2[z])
        {
            correct++;
        }
    }
    if (correct=length2)
    {
        printf("The second array is within the first array");
    }
    else 
    {
      goto end;
    }
    
return 0;
}