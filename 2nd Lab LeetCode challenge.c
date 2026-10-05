#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top=-1;

int main()
{
    char str[MAX];
    int i;
    char ch;

    printf("Enter brackets:");
    scanf("%s",str);

    for (i=0;str[i]!='\0';i++)
    {
        ch=str[i];

        if (ch== '(' || ch=='{' || ch=='[')
         {
            top++;
            stack[top]=ch;
         }
        else if (ch== ')' || ch=='}' || ch==']')
        {
            if (top==-1)
            {
                printf("False");
                return 0;
            }
            if ( (ch==')' && stack[top]=='(') || (ch=='}' && stack[top]=='{') || (ch==']' && stack[top]=='[') )
            {
                top--;
            }
            else
            {
                printf("False");
                return 0;
            }
        }
    }
    if (top==-1)
        printf("True");
    else
        printf("False");
    return 0;
}
