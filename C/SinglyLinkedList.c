#include <stdio.h>
#include<conio.h>
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

void insert_after()
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

void delete_start(){
    if(start!=NULL){
        int data=start->data;
        struct Node *temp;
        printf("To delete %d enter y else n : ",data);
        switch (getch())
        {
        case 'y':
            temp=start;
            start=start->next;
            free(temp);
            break;
        
        default:
            break;
        }
    }
}

void delete_end(){
    if(start!=NULL){
        int data;
        struct Node *temp=start,*prev=start;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        data=temp->data;
        printf("To delete %d enter y else n : ",data);
        switch (getch())
        {
        case 'y':
            prev->next=NULL;
            free(temp);
            break;
        
        default:
            break;
        }
    }
}

void delete_node(){
    int data;
    printf("Enter data to be deleted : ");
    scanf("%d",&data);
    struct Node *temp=start,*prv=start;
    while (temp->next!=NULL)
    {
        if(temp->data==data){
            prv->next=temp->next;
            free(temp);
            printf("Node %d deleted successfully..\n",data);
            return;
        }
        prv=temp;
        temp=temp->next;
    }
    printf("Node %d not found",data);
    
}

void delete_list(){
    struct Node *temp;
    printf("Are you sure to delete entire list (y/n): ");
    switch (getch())
    {
    case 'y':
        while (start!=NULL)
        {
            temp=start;
            start=start->next;
            free(temp);
        }
        printf("\nList deleted successfully..\n\n");
        break;
    
    default:
        break;
    }
}

void print()
{
    struct Node *ptr = start;
    printf("\nOutput : ");
    if(start==NULL){
        printf("List is empty...");
    }
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
        printf("Enter Your Choice : \n1. Insert at Begin\n2. Insert at End\n3. Insert Before\n4. Insert After\n5. Delete node from start\n6. Delete node from end\n7. Delete a given node\n8. Delete the entire list\n9. Print Entire List");
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
        case 4:
            insert_after();
            print();
        case 5:
            delete_start();
            print();
            break;
        case 6:
            delete_end();
            print();
            break;
        case 7:
            delete_node();
            print();
            break;
        case 8:
            delete_list();
            break;
        case 9:
            print();
            break;
        default:
            break;
        }
    } while (choice != 10);

    getchar();
    return 0;
}