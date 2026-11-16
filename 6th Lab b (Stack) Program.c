#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int val)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow \n");
        return;
    }

    struct node *temp;
    temp=top;
    printf("Element deleted :%d",temp->data);
    top=temp->next;
    free(temp);
}

void display()
{
    struct node *temp;
    if (top==NULL)
    {
        printf("Stack is empty \n");
        return;
    }
    temp=top;
    printf("Stack elements are \n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice,val;
    while(1)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            pop();
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
