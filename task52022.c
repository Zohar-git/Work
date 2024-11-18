#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LANG_SIZE 10
#define WORD_SIZE 15
typedef struct
{
    char **defenition;
    struct Word *next;
} Word;
typedef struct
{
    char **languages;
    int num_langu;
    Word *word_list;
} dictionary;
dictionary *dictionaries = NULL;
int amount_dict = 0;
void new_dictionary()
{
    // allocate space for a new dictionary
    amount_dict += 1;
    dictionaries = realloc(dictionaries, sizeof(dictionary) * (amount_dict));
    if (dictionaries == NULL)
    {
        printf("Failed to allocate memory :(");
        return;
    }
    // get amount of diff language and allocate memory for array of char* (for language)

    printf("Enter the amount of languages in this dictionary:\n");
    scanf("%d", &dictionaries[amount_dict - 1].num_langu);
    int num_lang = dictionaries[amount_dict - 1].num_langu;
    dictionaries[amount_dict - 1].languages = malloc(sizeof(char *) * num_lang);
    dictionaries[amount_dict - 1].word_list = NULL;

    // loop for entering the languages of this dict to and array of string pointers

    for (int i = 0; i < num_lang; i++)
    {
        dictionaries[amount_dict - 1].languages[i] = malloc(LANG_SIZE * sizeof(char));
        if (dictionaries[amount_dict - 1].languages[i] == NULL)
        {
            printf("Failed to allocate memory :(");
            return;
        }
        printf("Enter the %dst language:\n", i + 1);
        scanf("%s", dictionaries[amount_dict - 1].languages[i]);
    }
    printf("Great you created NEW Dictionary!\n");
    menu();
}
void add_word_dict()
{
    // add word to which dict?
    int dict_num = 0;
    printf("Enter the dictionary you want to add word to: 1 - %d\n", amount_dict);
    scanf("%d", &dict_num);
    // allocate memory for new word
    Word *new_word = malloc(sizeof(Word));
    // allocate memory for pointers for defenition in each language of the dictionary
    new_word->defenition = malloc(sizeof(char *) * dictionaries[dict_num - 1].num_langu);
    new_word->next = NULL;
    if (new_word->defenition == NULL)
    {
        printf("Failed to allocate memory :(");
    }

    // allocate memory for each defenition and entering them
    for (int i = 0; i < dictionaries[dict_num - 1].num_langu; i++)
    {
        new_word->defenition[i] = (char *)malloc(sizeof(char) * WORD_SIZE);
        if (new_word->defenition[i] == NULL)
        {
            printf("Failed to allocate memory :(");
        }
        printf("Enter the meaning in %s\n", dictionaries[dict_num - 1].languages[i]);
        scanf("%s", new_word->defenition[i]);
    }

    // Make head to the linked list and allocate memory for it
    Word *head;
    if (dictionaries[dict_num - 1].word_list == NULL)
    {
        dictionaries[dict_num - 1].word_list = new_word;
    }
    else
    {
        head = dictionaries[dict_num - 1].word_list;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = new_word;
    }
    printf("Great we added the word to the dictionary!\n");
    printf("\n");
    menu();
}
int print_word(int dict_num)
{
    Word *current;
    current = dictionaries[dict_num - 1].word_list;
    int i = 0;
    int choice = 0;
    if (current == NULL)
    {
        printf("There are no words in this Dictionary :(");
    }
    printf("Which word you want to delete ?\n");
    while (current != NULL)
    {
        printf("%d)", i + 1);
        for (int b = 0; b < dictionaries[dict_num - 1].num_langu; b++)
        {
            printf("%s    ", current->defenition[b]);
        }
        printf("\n");
        current = current->next;
        i++;
    }
    scanf("%d", &choice);
    free(current);
    return choice;
}
void delete_word_dictionary()
{

    int dict_num = 0;
    printf("Enter the dictionary you want to remove word from: 1 - %d\n", amount_dict);
    scanf("%d", &dict_num);
    int choice = print_word(dict_num);
    Word *current = dictionaries[dict_num - 1].word_list;
    Word *prev = NULL;
    for (int i = 1; i <= choice; i++)
    {
        if (i == choice)
        {
            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    menu();
}
void find_word_dictionary()
{
    int dict_num = 0;
    printf("Enter the dictionary you want to search a word in: 1 - %d\n", amount_dict);
    scanf("%d", &dict_num);
    char Word_find[WORD_SIZE] = {0};
    printf("Enter the word you are searching for :\n");
    scanf("%s", Word_find);
    Word *current;
    current = dictionaries[dict_num - 1].word_list;
    while (current != NULL)
    {
        for (int i = 0; i < dictionaries[dict_num - 1].num_langu; i++)
        {
            if (strcmp(current->defenition[i], Word_find) == 0)
            {
                printf("The word '%s' is in this dictionary :)\n", Word_find);
                for (int b = 0; b < dictionaries[dict_num - 1].num_langu; b++)
                {
                    printf("%s       ", current->defenition[b]);
                }
                printf("\n");
                menu();
            }
        }
        current = current->next;
    }
    printf("The word '%s' in not in this dictionary :(", Word_find);
}
void delete_dictionary()
{
    int dict_num = 0;
    printf("Enter the dictionary you want to search a word in: 1 - %d\n", amount_dict);
    scanf("%d", &dict_num);
    Word *current;
    current = dictionaries[dict_num - 1].word_list;
    Word *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
    free(dictionaries[dict_num - 1].languages);
}
void print_dict()
{
    int dict_num = 0;
    printf("Enter the dictionary you want to search a word in: 1 - %d\n", amount_dict);
    scanf("%d", &dict_num);
    Word *current;
    current = dictionaries[dict_num - 1].word_list;
    int i = 0;
    int choice = 0;
    if (current == NULL)
    {
        printf("There are no words in this Dictionary :(");
    }
    while (current != NULL)
    {
        printf("%d)", i + 1);
        for (int b = 0; b < dictionaries[dict_num - 1].num_langu; b++)
        {
            printf("%s    ", current->defenition[b]);
        }
        printf("\n");
        current = current->next;
        i++;
    }
}
void exit_program()
{
    for (int i = 0; i < amount_dict; i++)
    {
        Word *current;
        current = dictionaries[i].word_list;
        Word *temp;
        while (current != NULL)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(dictionaries[i].languages);
        free(dictionaries[i].word_list);
    }
    free(dictionaries);
    printf("Have a good day and thank you for using our Dictionary program :");
    exit(1);
}
void menu()
{
    int choice = 0;
    printf("Welcome to the dictionaries manager!\n Choose an option:\n");
    printf("1) Create a new dictionary\n");
    printf("2) Add a word to a dictionary\n");
    printf("3) Delete a word from a dictionary\n");
    printf("4) Find a word in a dictionary\n");
    printf("5) Delete a dictionary\n");
    printf("6) Print dictionary\n");
    printf("7) Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

        new_dictionary();
        break;
    case 2:
        add_word_dict();
        break;
    case 3:
        delete_word_dictionary();
        break;
    case 4:
        find_word_dictionary();
        break;

    case 5:
        delete_dictionary();
        break;
    case 6:
        print_dict();
        break;
    case 7:
        exit_program();
        break;
    }
}
int main(void)
{
    menu();
    return 0;
}