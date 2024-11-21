#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HAND_SIZE 5
typedef struct
{
    char *hand;
    int bid;
} hand;
int hand_amount = 0;
hand *Hands = NULL;
hand *Hands_in_order = NULL;
int **Hands_order = NULL;

char **FIVE_KIND = NULL;
char **FOUR_KIND = NULL;
char **FULL_HOUSE = NULL;
char **THREE_KIND = NULL;
char **TWO_PAIR = NULL;
char **ONE_PAIR = NULL;
char **HIGH_CARD = NULL;

int five_kind = 0, four_kind = 0, three_kind = 0, full_house_kind = 0, two_pair_kind = 0, pair_kind = 0, high_card_kind = 0;

int add_hands()
{
    hand_amount++;
    Hands = (hand *)realloc(Hands, hand_amount * sizeof(hand));
    Hands[hand_amount - 1].hand = malloc(sizeof(char) * (HAND_SIZE + 1));
    printf("Enter the hand you want to play(Contains 5 characters):\n");
    scanf("%s", Hands[hand_amount - 1].hand);
    if (strcmp(Hands[hand_amount - 1].hand, "0") == 0)
    {
        return 1;
    }
    printf("Enter the bid for that hand\n");
    scanf("%d", &Hands[hand_amount - 1].bid);
    return 0;
}
void print_hands()
{
    printf("This are the Hands and there bids you entered to the system:\n");
    for (int i = 0; i < hand_amount - 1; i++)
    {
        printf("%s       ", Hands[i].hand);
        printf("%d\n", Hands[i].bid);
    }
}
void Hand_order_inarray()
{
    Hands_order = realloc(Hands_order, hand_amount * sizeof(int *));
    for (int i = 0; i < hand_amount; i++)
    {
        Hands_order[i] = malloc(13 * sizeof(int));   // 13 because there are 13 cards in a deck
        memset(Hands_order[i], 0, 13 * sizeof(int)); // Initialize all elements to 0
        for (int b = 0; b < HAND_SIZE; b++)
        {
            char card = Hands[i].hand[b];
            int index = -1;

            if (card == 'A')
                index = 0; // Ace
            else if (card == '2')
                index = 1;
            else if (card == '3')
                index = 2;
            else if (card == '4')
                index = 3;
            else if (card == '5')
                index = 4;
            else if (card == '6')
                index = 5;
            else if (card == '7')
                index = 6;
            else if (card == '8')
                index = 7;
            else if (card == '9')
                index = 8;
            else if (card == 'J')
                index = 10; // Jack
            else if (card == 'Q')
                index = 11; // Queen
            else if (card == 'K')
                index = 12; // King

            if (index >= 0 && index < 13)
                Hands_order[i][index]++;
        }
    }
}
void sort_hands(int **Hands_order)
{
    for (int c = 0; c < hand_amount; c++)
    {
        int pair = 0, three = 0, check = 0;
        for (int i = 0; i < 13; i++)
        {
            if (Hands_order[c][i] == 5)
            {
                five_kind++;
                FIVE_KIND = realloc(FIVE_KIND, sizeof(char *) * five_kind);
                FIVE_KIND[five_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(FIVE_KIND[five_kind - 1], Hands[c].hand);
                break;
            }
            if (Hands_order[c][i] == 4)
            {
                four_kind++;
                FOUR_KIND = realloc(FOUR_KIND, sizeof(char *) * four_kind);
                FOUR_KIND[four_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(FOUR_KIND[four_kind - 1], Hands[c].hand);
                break;
            }
            if (Hands_order[c][i] == 3)
            {
                three++;
            }
            if (Hands_order[c][i] == 2)
            {
                pair++;
            }
            if (pair == 1 && three == 1)
            {
                full_house_kind++;
                FULL_HOUSE = realloc(FULL_HOUSE, sizeof(char *) * full_house_kind);
                FULL_HOUSE[full_house_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(FULL_HOUSE[full_house_kind - 1], Hands[c].hand);
            }
            else if (pair == 2)
            {
                two_pair_kind++;
                TWO_PAIR = realloc(TWO_PAIR, sizeof(char *) * two_pair_kind);
                TWO_PAIR[two_pair_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(TWO_PAIR[two_pair_kind - 1], Hands[c].hand);
            }
            else if (pair == 1)
            {
                pair_kind++;
                ONE_PAIR = realloc(ONE_PAIR, sizeof(char *) * pair_kind);
                ONE_PAIR[pair_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(ONE_PAIR[pair_kind - 1], Hands[c].hand);
            }
            if (Hands_order[c][i] == 1)
            {
                check++;
            }
            if (check == 5)
            {
                high_card_kind++;
                HIGH_CARD = realloc(HIGH_CARD, sizeof(char *) * high_card_kind);
                HIGH_CARD[high_card_kind - 1] = malloc(HAND_SIZE + 1);
                strcpy(HIGH_CARD[high_card_kind - 1], Hands[c].hand);
            }
        }
    }
}
/*void check_same_handtype()
{
    if (sizeof(FIVE_KIND)>sizeof(char*))
    {
        int x = 0;
        for (int i = 0; i < HAND_SIZE+1; i++)
        {
            if(FIVE_KIND[x][i] == FIVE_KIND[x+1][i])
            {
                continue;
            }
            if
        }

    }






}
*/
void print_sorted_hands()

{
    if (five_kind != 0)
    {
        printf("FIVE KIND: \n");
        for (int i = 0; i < five_kind; i++)
        {
            printf("%s\n", FIVE_KIND[i]);
        }
    }
    if (four_kind != 0)
    {
        printf("FOUR KIND:\n");
        for (int i = 0; i < four_kind; i++)
        {
            printf("%s\n", FOUR_KIND[i]);
        }
    }
    if (full_house_kind != 0)
    {
        printf("FULL HOUSE:\n");
        for (int i = 0; i < full_house_kind; i++)
        {
            printf("%s\n", FULL_HOUSE[i]);
        }
    }
    if (three_kind != 0)
    {
        printf("THREE KIND:\n");
        for (int i = 0; i < three_kind; i++)
        {
            printf("%s\n", THREE_KIND[i]);
        }
    }
    if (two_pair_kind != 0)
    {
        printf("TWO PAIR:\n");
        for (int i = 0; i < two_pair_kind; i++)
        {
            printf("%s\n", TWO_PAIR[i]);
        }
    }
    if (pair_kind != 0)
    {
        printf("ONE PAIR:\n");
        for (int i = 0; i < pair_kind; i++)
        {
            printf("%s\n", ONE_PAIR[i]);
        }
    }
    if (high_card_kind != 0)
    {
        printf("HIGH CARD:\n");
        for (int i = 0; i < high_card_kind; i++)
        {
            printf("%s\n", HIGH_CARD[i]);
        }
    }
}
int main()
{

    int y = 0;
    printf("Welcome to Camel Cards !\n");
    printf("When you want to stop adding hands type in 0!\n");
    while (1)
    {
        y = add_hands();
        if (y == 1)
        {
            break;
        }
    }
    print_hands();
    Hand_order_inarray(Hands_order);
    sort_hands(Hands_order);
    print_sorted_hands();
    return 0;
}