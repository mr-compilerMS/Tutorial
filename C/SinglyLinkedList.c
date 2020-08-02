#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start;

struct Node *createNewNode()
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}

void insert_at_end()
{
    struct Node *new, *ptr;
    new = createNewNode();
    if (start != NULL)
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    else
    {
        start = new;
    }
}

void insert_at_begin()
{
    struct Node *ptr, *new;
    new = createNewNode();
    new->next = start;
    start = new;
}

void insert_before()
{
    struct Node *ptr = start, *new, *preptr;
    new = createNewNode();
    int d;
    printf("Enter the value before which the data has to be inserted :");
    scanf("%d", &d);

    if (start == NULL)
    {
        printf("Error list doesnt exists");
        return;
    }

    while (ptr->data != d)
    {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("value doesnt exists");
            break;
        }
    }
    preptr->next = new;
    new->next = ptr;
}

void print()
{
    struct Node *ptr = start;
    printf("\nOutput : ");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

int main()
{

    int choice;
    do
    {
        printf("Enter Your Choice : \n1. Insert at Begin\n2. Insert at End\n3. Insert Before");
        printf("\n10. Exit\n==>");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_at_begin();
            print();
            break;

        case 2:
            insert_at_end();
            print();
            break;

        case 3:
            insert_before();
            print();
            break;
        default:
            break;
        }
    } while (choice != 10);

    getchar();
    return 0;
}