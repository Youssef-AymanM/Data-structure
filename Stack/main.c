#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} Node;

Node *head = NULL;

void create();
void display();
void enter_end();
void delete_end();

int main()
{
    int choice;

    while(choice != 5)
    {
        printf("\n\t\t\t\t\t\t\tMENU\t\t\n");
        printf("\n1. Create\n");
        printf("\n2. Display\n");
        printf("\n3. Enter at the end\n");
        printf("\n4. Delete\n");
        printf("\n5. Exit\n");
        printf("\n_____________________________________________\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            enter_end();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }

    return 0;
}

void create()
{
    Node *temp = malloc(sizeof(Node));

    if(temp == NULL)
    {
        printf("\nNo space available.\n");
        return;
    }

    printf("\nEnter the data value for the node: ");
    scanf("%d", &(temp->data));
    temp->link = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        Node *ptr = head;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void display()
{
    Node *ptr;

    if(head == NULL)
        printf("\nThe list is empty.\n");
    else
    {
        ptr = head;
        printf("\nThe list contains: ");
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
void enter_end()
{
    Node *ptr;
    ptr = head;
    Node *temp = malloc(sizeof(Node));

    if(temp == NULL)
    {
        printf("\nOut of Memory Space.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &(temp->data));
    temp->link = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void delete_end()
{
    if(head == NULL)
    {
        printf("The list is empty.\n");
    }
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

