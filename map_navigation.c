#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *Name;
    char *LEFT;
    char *Right;
} Node;
int map_navigation(Node *head, Node *current)
{
    int amount_steps = 0;
    char instructions[] = "LRRLLRLLRRLRRLLRRLLRLRRRLLRRLRRRLRRLRRRLLRRLLRLLRRLRLRRRLRRLLRRRLRLRRLRRLRLRLRLLRLRRRLLRLLRRLRRRLRLRLRRRLRRLLRRRLRLRRLRRLLRRLRRRLRRLRRLRRLLRLRLRRLLRLLRRRLRRLRRLRRRLRLLRRRLRRRLRRLLRRRLRRRLRLLRLRRLRLLRRLLLRRLRRLRRLRLRRRLRRLLRLRRRLRRLRLLLRRLRRLRRRLLLRLLLLRRLRLLLRLRRRLRRRLRLRRRLLLLRLRRRLRLLLRRLRLRRLRRLRRRLRRRR";
    char *p = instructions;
    while ( p != NULL)
    {
        if (strcmp("ZZZ", current->Name) == 0)
        {
            return amount_steps;
            break;
        }
        if (*p == "L")
        {
            current = current->LEFT;
            amount_steps++;
            p++;
        }
        if (*p == "R")
        {
            current = current->Right;
            amount_steps++;
            p++;
        }
    }
    if (strcmp("ZZZ", current->Name) != 0)
    {
        map_navigation(head, current);
    }
}
int main(void)
{
    int read = 0;
    int new_node = 0;
    FILE *file = fopen("textfile.txt", "r");
    if (file == NULL)
    {
        printf("The file didnt open :(");
    }
    char ch;
    while (ch = fgetc(file) != EOF)
    {
        if (ch != '(' && ch != ')' && ch != ',' && ch != '=')
        {
            ungetc(ch, file);
        }
    }
    Node *head = NULL;
    while (!feof(file))
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->Name = malloc(sizeof(char) * 4);
        new_node->Right = malloc(sizeof(char) * 4);
        new_node->LEFT= malloc(sizeof(char) * 4);
        new_node->Right = NULL;
        new_node->LEFT = NULL;
        read = fscanf(file, "%s,%s,%s", new_node->Name,new_node->LEFT, new_node->Right);
        if (read != 3)
        {
            printf("There is a problem with the file");
        }
        if (strcmp(new_node->Name, "AAA") == 0)
        {
            head = new_node;
        }
    }
    fclose(file);
    Node *current = head;
    map_navigation(head, current);
    return 0;
}