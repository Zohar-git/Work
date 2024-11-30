#include <stdio.h>
int IsPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int Goldbach(int y)
{
    for (int i = 2; i < y; i++)
    {
        if (IsPrime(i) == 1 && IsPrime(y - i) == 1)
        {
            printf("%d %d", i, y - i);
            return 0;
        }
    }
    return 1;
}
int main(void)
{
    Goldbach(7);
    return 0;
}