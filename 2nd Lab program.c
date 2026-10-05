#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;
void push(char ch)
{
    top++;
    stack[top]=ch;
}

char pop()
{
    char ch=stack[top];
    top--;
    return ch;
}

int precedence (char ch)
{
    if (ch == '*' || ch== '/')
    {
        return 2;
    }
    if (ch=='+' || ch=='-')
    {
        return 1;
    }
    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j=0;
    char ch;

    printf("Enter the infix expression:");
    scanf("%[^\n]",infix);
    strcat(infix,")");
    push('(');

    for (i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];

        if (ch== ' ')
        {
            continue;
        }
        if (ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if (ch==')')
        {
            while (stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            pop();
        }
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            while ((stack[top]!='(') &&(precedence(stack[top])>=precedence(ch)))
                   {
                       postfix[j++]=pop();
                   }
                   push(ch);
        }
    }
    postfix[j]='\0';
    printf("Postfix Expression %s \n",postfix);

    return 0;
}
