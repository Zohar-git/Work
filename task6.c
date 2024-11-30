#include<stdio.h>
int main(void)
{
int size,rows;
char letter;
//check if the letter and number is like the requirements//
printf("Enter a big letter:");
scanf("%c",&letter);
if(letter<65 || letter>90)
{
    printf("You didnt enter big letter :(");
    return 1;
}
printf("Enter odd number between 1-21:");
scanf("%d",&size);
if(size%2==0 || size>21 || size<0 )
{
    printf("This number is not answering the requirements");
    return 1;
}
rows = size/2+1;
// loops for upper pyramid//
for(int a = 0;a<rows;a++ )// amount of rows in pyramid//
{
for(int n = 0;n<a;n++)
{
     printf(" ");
}
for (int c = 0;c<size-(2*a);c++)
{
    printf("%c",letter);
}
printf("\n");
}
//loops for lower pyramid//
char lower_letter = tolower(letter);
for (int b = 1; b <= rows; b++)
{
for (int i = 1; i <= rows-b; i++)
{
    printf(" ");
}
for (int y = 1;y<=2*b-1;y++)
{
    printf("%c",lower_letter);
}
printf("\n");
}
    return 0;
}































