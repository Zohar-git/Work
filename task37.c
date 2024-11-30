#include <stdio.h>
int amount_diff_ways(int ledder)
{
    if (ledder == 1)
    {
        return 1;
    }
    if (ledder == 2)
    {
        return 2;
    }
    return amount_diff_ways(ledder-1)+amount_diff_ways(ledder-2);

}
int main(void)
{
    int ledder;
    printf("Enter the size of the ledder:");
    scanf("%d", &ledder);
    int y = amount_diff_ways(ledder);
    printf("%d",y);
    return 0;
}