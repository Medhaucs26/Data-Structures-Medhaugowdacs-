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

void delete_at_first()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("The linked list is empty\n");
        return;
    }
    temp=head;
    head=head->next;
    printf("Deleted at first , the item is %d->",temp->data);
    free(temp);
}

void delete_at_position() {
    struct node *temp, *prev;
    int position, count = 1;

    if (head == NULL) {
        printf("The linked list is empty\n");
        return;
    }

    printf("Enter the position where you want to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("The position is not found\n");
        return; // Prevents NULL pointer dereference
    }

    if (prev == NULL) {
        head = head->next; // Deleting the first node
    } else {
        prev->next = temp->next;
    }

    printf("Deleted at position %d, the element is %d\n", position, temp->data);
    free(temp);
}

void delete_at_end()
{
    struct node *temp,*prev;
    if(head==NULL)
    {
        printf("The linked list is empty\n");
        return;
    }

    temp=head;
    prev=NULL;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        head=NULL;
    }
    else
    {
        prev->next=NULL;
    }
    printf("Deleted at end , the element is %d",temp->data);
    free(temp);
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
        printf("\n1.Create \n2.Delete at first \n3.Delete at Position \n4.Delete at End \n5.Display \n6.Exit");

        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            delete_at_first();
            break;
        case 3:
            delete_at_position();
            break;
        case 4:
            delete_at_end();
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
