#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int data)
{
    if (top==MAX-1)
    {
        printf("Stack Overflow \n");
        return;
    }
    top++;
    stack[top]=data;
}

int pop()
{
    if (top==-1)
    {
        printf("Stack Underflow \n");
        return -1;
    }
    int value=stack[top];
    stack[top]=0;
    top--;
    return value;
}

void display()
{
    if (top==-1)
    {
        printf("Stack Underflow \n");
        return;
    }
    int i;
    printf("The elements are : ");
    for (i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    return;
}

int main()
{
    int choice,data;
    while(1)
    {
        printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            {
                printf("Enter data to push:");
                scanf("%d",&data);
                push(data);
                break;
            }
        case 2:
            {
                int value =pop();
                if (value != -1)
                    {
                        printf("Popped element :%d \n",value);
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
                printf("Input a valid number\n");
            }
            break;
        }
    }
}
