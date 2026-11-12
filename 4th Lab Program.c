#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create()
{
    struct node *newnode, *temp;
    int n,i;
    printf("Enter number of nodes :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            printf("Memory allocation failed");
            return;
        }
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
        temp->next=newnode;
        }
    }
}

void insert_at_first()
{
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_at_position()
{
    struct node *newnode, *temp;
    int position , i;
    printf("Enter position:");
    scanf("%d",&position);

    if(position<1)
    {
        printf("Invalid position \n");
        return;
    }
    if(position==1)
    {
        insert_at_first();
        return;
    }
    temp=head;
    for(i=1;i<position-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Position is not found \n");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}

void insert_at_end()
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display()
{
    struct node *temp;
    if (head==NULL)
    {
        printf("The linked list is empty\n");
        return;
    }
    temp=head;
    printf("Linked List\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create \n2.Insert at first \n3.Insert at Position \n4.Insert at End \n5.Display \n6.Exit");

        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_at_first();
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            insert_at_end();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
