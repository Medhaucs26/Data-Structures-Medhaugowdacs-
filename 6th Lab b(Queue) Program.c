#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data=num;
    newnode->next=NULL;

    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue underflow \n");
        return;
    }
    temp=front;
    printf("Element deleted %d",temp->data);
    front=front->next;

    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
}

void display()
{
    struct node *temp=front;
    if (front==NULL)
    {
        printf("Queue is empty \n");
        return;
    }
    printf("Queue elements are: \n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice,num;
    while(1)
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d",&num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}

