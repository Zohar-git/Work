#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *name;
    char *left;
    char *right;
    struct Node *left_next;
    struct Node *right_next;
    struct Node *next;
} Node;

int main()
{
    Node *head = NULL;
    Node *head_list = NULL;
    Node *current = NULL;
    char instructions[] = "LRLRLRLLRRLRRLRRRLRRLRLLRRRLRRRLRRLLLLRRRLRLLRRLRRLRRLLLRRRLRRRLRRLRLRRLRLRLRLLRRRLRRRLLRRRLRRRLRRRLRLLLRRLRLRRRLRLRRRLLRRRLRLLRLRRRLRLRRRLRRLLRLRLRRLRLRLRRLRLRLRRRLRRLRLLRRLRRRLRRRLRRLRRRLRRLRLRRRLLRRRLLRRLRLRRRLRRRLLRRRLRLRRLRLRLRRLRLLRRLRLRLRRLRRRLRRRLRLRRLRRLLLRRRLLRLRRRLLRRRR";

    FILE *map = fopen("textfile.txt", "r");
    if (map == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // malloc space
    while (1)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->name = malloc(sizeof(char) * 4);
        new_node->left = malloc(sizeof(char) * 4);
        new_node->right = malloc(sizeof(char) * 4);
        new_node->left_next = NULL;
        new_node->right_next = NULL;
        new_node->next = NULL;

        char name[4], left[4], right[4];

        // Read data
        if (fscanf(map, " %3s = (%3[^,], %3[^)])", name, left, right) != 3)
        {
            break; //check
        }

        strcpy(new_node->name, name);
        strcpy(new_node->left, left);
        strcpy(new_node->right, right);

        if (current == NULL)
        {
            head_list = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }

        if (strcmp(new_node->name, "AAA") == 0)
        {
            head = new_node;
        }
    }
    fclose(map);

    // Link the left and right nodes
    current = head_list;
    while (current != NULL)
    {
        Node *anchor = head_list;
        while (anchor != NULL)
        {
            if (strcmp(current->left, anchor->name) == 0)
            {
                current->left_next = anchor;
            }
            if (strcmp(current->right, anchor->name) == 0)
            {
                current->right_next = anchor;
            }
            anchor = anchor->next;
        }
        current = current->next;
    }

    // Navigate through the instructions
    int steps_amount = 0;
    Node *current_node = head;
    int i = 0;
    int instructions_len = strlen(instructions);
    
    while (strcmp(current_node->name, "ZZZ") != 0)
    {
        if (instructions[i] == 'R')
        {
            if (current_node->right_next != NULL)
                current_node = current_node->right_next;
            else
                break; 
        }
        else
        {
            if (current_node->left_next != NULL)
                current_node = current_node->left_next;
            else
                break; 
        }

        steps_amount++;

        i++; 
        if (i == instructions_len) /back to start
        {
            i = 0;
        }
    }

    if (strcmp(current_node->name, "ZZZ") == 0)
    {
        printf("Amount of steps: %d\n", steps_amount);
    }
    else
    {
        printf("Error: Couldn't reach ZZZ\n");
    }

    return 0;
}
