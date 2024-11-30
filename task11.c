#include <stdio.h>
#define AmountLettersAscii 122
#define MIN 'a'
#define max 'z'
int main(void)
{
    int letters[AmountLettersAscii + 1] = {0};
    char x = 0;
    printf("Enter 10 letters for a-z:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &x);
        if (x < MIN || x > max)
        {
            continue;
        }
        letters[x]++;
    }
    for (int i = 0; i < AmountLettersAscii + 1; i++)
    {
        if (letters[i] > 0)
        {
            printf("%c appears %d times\n", i, letters[i]);
        }
    }
    return 0;
}