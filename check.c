#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *Name;
    struct Node *LEFT;
    struct Node *Right;
} Node;

int map_navigation(Node *head, Node *current)
{
    int amount_steps = 0;
    char instructions[] = "LRRLLRLLRRLRRLLRRLLRLRRRLLRRLRRRLRRLRRRLLRRLLRLLRRLRLRRRLRRLLRRRLRLRRLRRLRLRLRLLRLRRRLLRLLRRLRRRLRLRLRRRLRRLLRRRLRLRRLRRLLRRLRRRLRRLRRLRRLLRLRLRRLLRLLRRRLRRLRRLRRRLRLLRRRLRRRLRRLLRRRLRRRLRLLRLRRLRLLRRLLLRRLRRLRRLRLRRRLRRLLRLRRRLRRLRLLLRRLRRLRRRLLLRLLLLRRLRLLLRLRRRLRRRLRLRRRLLLLRLRRRLRLLLRRLRLRRLRRLRRRLRRRR";
    char *p = instructions;

    while (p != NULL)
    {
        if (strcmp("ZZZ", current->Name) == 0)
        {
            return amount_steps;
        }

        if (*p == 'L')
        {
            current = current->LEFT;
            amount_steps++;
            p++;
        }
        else if (*p == 'R')
        {
            current = current->Right;
            amount_steps++;
            p++;
        }
    }

    // Recursion will terminate if "ZZZ" is reached
    if (strcmp("ZZZ", current->Name) != 0)
    {
        return map_navigation(head, current);
    }

    return amount_steps;
}

int main(void)
{
    int read = 0;
    FILE *file = fopen("textfile.txt", "r");
    if (file == NULL)
    {
        printf("The file didn't open :(\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch != '(' && ch != ')' && ch != ',' && ch != '=')
        {
            ungetc(ch, file); // Keep the character for later reading
        }
    }

    Node *head = NULL;
    while (!feof(file))
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->Name = malloc(sizeof(char) * 4);
        new_node->Right = malloc(sizeof(char) * 4);
        new_node->LEFT = malloc(sizeof(char) * 4);

        new_node->Right = NULL;
        new_node->LEFT = NULL;

        read = fscanf(file, "%s,%s,%s", new_node->Name, new_node->LEFT, new_node->Right);
        if (read != 3)
        {
            printf("There is a problem with the file\n");
            return 1;
        }

        if (strcmp(new_node->Name, "AAA") == 0)
        {
            head = new_node;
        }
    }

    fclose(file);

    Node *current = head;
    int steps = map_navigation(head, current);
    printf("Total steps: %d\n", steps);

    return 0;
}
