#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int num)
{
    if (rear==MAX-1)
    {
        printf("Queue Overflow, this element will not be inserted");
        return;
    }
    if (front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=num;
}

int dequeue()
{
    if (front==-1)
    {
        printf("Queue Underflow");
        return -1;
    }
    int value=queue[front];
    if (front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return value;
}

void display()
{
    if (front==-1)
    {
        printf("Queue is empty");
        return;
    }
    int i;
    printf("The elements in the queue are:");
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    return;
}

int main()
{
    int choice,num;
    while(1)
    {
        printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                printf("Enter element to insert to queue:");
                scanf("%d",&num);
                enqueue(num);
                break;
            }
        case 2:
            {
                int value=dequeue();
                if (value!=-1){
                printf("The deleted element is %d ",value);}
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
                printf("Please enter a valid choice");
                break;
            }
            break;
        }
    }
}
