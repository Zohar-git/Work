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
    Node **heads = NULL;
    int b = 0;
    Node *anchor = NULL;
    Node *head_list = NULL;
    Node *current = NULL;
    char instructions[] = "LRRLLRLLRRLRRLLRRLLRLRRRLLRRLRRRLRRLRRRLLRRLLRLLRRLRLRRRLRRLLRRRLRLRRLRRLRLRLRLLRLRRRLLRLLRRLRRRLRLRLRRRLRRLLRRRLRLRRLRRLLRRLRRRLRRLRRLRRLLRLRLRRLLRLLRRRLRRLRRLRRRLRLLRRRLRRRLRRLLRRRLRRRLRLLRLRRLRLLRRLLLRRLRRLRRLRLRRRLRRLLRLRRRLRRLRLLLRRLRRLRRRLLLRLLLLRRLRLLLRLRRRLRRRLRLRRRLLLLRLRRRLRLLLRRLRLRRLRRLRRRLRRRR";

    FILE *map = fopen("textfile.txt", "r");
    if (map == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read the nodes from the file
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

        // Read the node data
        if (fscanf(map, " %3s = (%3[^,], %3[^)])", name, left, right) != 3)
        {
            break; // Exit if the line format is incorrect or file ends
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

        if (new_node->name[2] == 'A') 
        {
          b++;
          heads = realloc(heads,b*sizeof(Node*));
          heads[b-1] = malloc(sizeof(Node));
          heads[b-1] = new_node;
        }
    }
    fclose(map);

    // Link the left and right nodes
    current = head_list;
    while (current != NULL)
    {
        anchor = head_list;
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
    long goal_num = 0;
    int steps_amount = 0;
    int i = 0;
    int y = 0;
    int instructions_len = strlen(instructions);
 while (1)
 {
    for (y = 0; y < b; y++)
    {
        if (instructions[i] == 'R')
        {
            if (heads[y]->right_next != NULL)
                heads[y] = heads[y]->right_next;
            if (heads[y]->name[2] == 'Z')
                goal_num++;
        }
        else
        {
            if (heads[y]->left_next != NULL)
                heads[y] = heads[y]->left_next;
            if (heads[y]->name[2] == 'Z')
                goal_num++;
        }
    }

    if (goal_num == b) 
    {
        printf("Amount of headers: %d\n", b);
        printf("Amount of steps: %d\n", steps_amount);
        return 0;
    }
    steps_amount++;
        i++; 
        if (i == instructions_len) 
        {
            i = 0;
        }
    goal_num = 0;
}
return 0;
}