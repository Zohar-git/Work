#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *Name;
    char *LEFT;
    char *RIGHT;
    struct node*LEFT_NEXT ;
    struct node* RIGHT_NEXT;
} Node;
int map_navigation(Node *head, Node *current, int *amount_steps)
{
    char instructions[] = "LRRLLRLLRRLRRLLRRLLRLRRRLLRRLRRRLRRLRRRLLRRLLRLLRRLRLRRRLRRLLRRRLRLRRLRRLRLRLRLLRLRRRLLRLLRRLRRRLRLRLRRRLRRLLRRRLRLRRLRRLLRRLRRRLRRLRRLRRLLRLRLRRLLRLLRRRLRRLRRLRRRLRLLRRRLRRRLRRLLRRRLRRRLRLLRLRRLRLLRRLLLRRLRRLRRLRLRRRLRRLLRLRRRLRRLRLLLRRLRRLRRRLLLRLLLLRRLRLLLRLRRRLRRRLRLRRRLLLLRLRRRLRLLLRRLRLRRLRRLRRRLRRRR";
    char *p = instructions;
    while ( p != NULL)
    {
        if (strcmp("ZZZ", current->Name) == 0)
        {
            return;
        }
        if (*p == 'L')
        {
            current = current->LEFT_NEXT;
            (*amount_steps)++;
            p++;
            continue;
        }
        if (*p == 'R')
        {
            current = current->RIGHT_NEXT;
            (*amount_steps)++;
            p++;
            continue;
        }
    }
    if (strcmp("ZZZ", current->Name) != 0)
    {
        map_navigation(head, current,amount_steps);
    }
}
int main(void)
{
    int read = 0;
    int new_node = 0;
    int amount_steps = 0;
    FILE *file = fopen("textfile.txt", "r");
    if (file == NULL)
    {
        printf("The file didnt open :(");
    }
    char ch = 0 ;
    while (ch = fgetc(file) != NULL)
    {
        if (ch != '(' && ch != ')' && ch != ',' && ch != '=' && ch != "/n")
        {
            ungetc(ch,file);
        }
    }
    Node *head = NULL;
    Node *curr = NULL;
    while (!feof(file))
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->Name = malloc(sizeof(char) * 4);
        new_node->RIGHT = malloc(sizeof(char) * 4);
        new_node->LEFT= malloc(sizeof(char) * 4);
        new_node->RIGHT_NEXT = NULL;
        new_node->LEFT_NEXT = NULL;
        read = fscanf(file, "%s,%s,%s", new_node->Name,new_node->LEFT, new_node->RIGHT);
        if (read != 3)
        {
            printf("There is a problem with the file");
        }
        if (strcmp(new_node->Name, "AAA") == 0)
        {
            head = new_node;
            curr = head;
        }
        if (strcmp(curr->LEFT,new_node->Name) == 0)
        {
            curr->LEFT_NEXT = new_node;
        }
        if (strcmp(curr->RIGHT,new_node->Name) == 0)
        {
            curr->RIGHT_NEXT = new_node;
        }
    }
    fclose(file);
    Node *current = head;
    map_navigation(head, current, &amount_steps);
    printf("The amount of steps to get out of the desert is : %d",amount_steps);
    return 0;
}