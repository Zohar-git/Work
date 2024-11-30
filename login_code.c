#include <stdio.h>
int login(int id)
{
    while (1)
    {
        int x;
        printf("Enter ID to login:");
        scanf("%d", &x);
        if (x == id)
        {
            printf("You logged in!");
            break;
        }
        else
        {
            printf("Invalid id,try again! \n");
        }
    }
}
int main(void)
{
    static int ID = 0;
    printf("Enter your ID:");
    scanf("%d", &ID);
    printf("Your ID is saved!\n");
    login(ID);
    return 0;
}