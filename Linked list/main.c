#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} Node;

Node *head = NULL;

void create();
void display();
void enter_begin();
void enter_pos();
void enter_end();
void delete_begin();
void delete_pos();
void delete_end();

int main()
{
    int choice;

    while(choice != 9)
    {
        printf("\n\t\t\t\t\t\t\tMENU\t\t\n");
        printf("\n1. Create\n");
        printf("\n2. Display\n");
        printf("\n3. Enter at the beginning\n");
        printf("\n4. Enter at any position\n");
        printf("\n5. Enter at the end\n");
        printf("\n6. Delete at the beginning\n");
        printf("\n7. Delete at any position\n");
        printf("\n8. Delete at the end\n");
        printf("\n9. Exit\n");
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
            enter_begin();
            break;
        case 4:
            enter_pos();
            break;
        case 5:
            enter_end();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            delete_end();
            break;
        case 9:
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

void enter_begin()
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
        temp->link = head;
        head = temp;
    }
}

void enter_pos()
{
    Node *ptr;
    Node *temp = malloc(sizeof(Node));
    int i, pos;

    if(temp == NULL)
    {
        printf("\nNo space available.\n");
        return;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("\nEnter the data value for the node: ");
    scanf("%d", &(temp->data));
    temp->link = NULL;

    if (pos == 0)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        ptr = head;
        for(i = 0; i < pos - 1; i++)
        {
            ptr = ptr->link;
            if(ptr == NULL)
            {
                printf("\nPosition not found:\n");
                return;
            }
        }
        temp->link = ptr->link;
        ptr->link = temp;
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



void delete_begin()
{
    Node *ptr;
    if(head == NULL)
    {
        printf("\nList is Empty.\n");
        return;
    }
    else
    {
        ptr = head;
        head = head->link;
        printf("\nThe deleted element is: %d\n", ptr->data);
        free(ptr);
    }
}

void delete_pos()
{
    int pos;
    Node *temp, *ptr;
    if(head == NULL)
    {
        printf("\nThe List is Empty.\n");
        return;
    }
    else
    {
        printf("\nEnter the position of the node to be deleted: ");
        scanf("%d", &pos);
        if(pos == 0)
        {
            ptr = head;
            head = head->link;
            printf("\nThe deleted element is: %d\n", ptr->data);
            free(ptr);
        }
        else
        {
            ptr = head;
            for(int i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->link;
                if(ptr == NULL)
                {
                    printf("\nPosition not Found.\n");
                    return;
                }
            }
            temp->link = ptr->link;
            printf("\nThe deleted element is: %d\n", ptr->data);
            free(ptr);
        }
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
