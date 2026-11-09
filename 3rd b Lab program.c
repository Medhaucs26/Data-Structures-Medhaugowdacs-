#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int num)
{
    if ((rear+1)%MAX==front)
    {
        printf("Circular Queue overflow");
        return;
    }
    if (front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%MAX;
    }
    queue[rear]=num;
}

int dequeue()
{
    if(front==-1)
    {
        printf("Circular Queue Underflow");
        return -1;
    }
    int val=queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
    return val;
}

void display()
{
    if (front==-1)
    {
        printf("Circular queue is empty");
        return;
    }
    int i=front;
    printf("The elements of the circular queue are:");
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
        {
            break; // Stop after printing the rear element
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice,num;
    while(1)
    {
        printf("\n 1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                printf("Enter your element:");
                scanf("%d",&num);
                enqueue(num);
                break;
            }
        case 2:
            {
                int val=dequeue();
                if (val!=-1)
                {
                    printf("Element deleted %d",val);

                }
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                exit(0);
                break;
            }
        default:
            {
                printf("Invalid choice");
                break;
            }
        }
    }
}
