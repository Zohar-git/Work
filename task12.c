#include <stdio.h>
#define AmountCapital 26
#define Amountletters 256
int main(void)
{
    char x = 0;
    int break_point = 0;
    int amount_capital_sentence = 0;
    char sentence[Amountletters];
    printf("Enter a sentence:");
    for (int i = 0; i < Amountletters; i++)
    {
        scanf("%c", &x);
        sentence[i] = x;
        break_point = i;
        if (x == '\n')
        {
            break;
        }
    }
    char A = 'A';
    for (int y = 0; y < break_point; y++)
    {
        for (int z = 0; z < break_point; z++)
        {
            if (sentence[z] == A)
            {
                amount_capital_sentence++;
                A++;
            }
        }
    }
    if (amount_capital_sentence == AmountCapital)
    {
        printf("All the capital letters are in this sentence!Good job \n");
    }
    else
    {
        printf("not all the capital letters are in this sentence :(");
    }
    return 0;
}