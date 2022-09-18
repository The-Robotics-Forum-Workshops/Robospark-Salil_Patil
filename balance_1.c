#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int top=-1;
int stack[100];

void push(char);
char pop();
int match(char a,char b);
int check(char []);

int main()
{
        char exp[100];
        int valid;
        printf("Enter an algebraic expression : ");
        gets(exp);

        int i;
        char temp;
        for(i=0;i<strlen(exp);i++)
        {
                if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        push(exp[i]);
                if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                        if(top==-1)    /*stack empty*/
                        {
                                printf("Right parentheses are more than left parentheses\n");
                                printf("Invalid expression\n");
                                return 0;
                        }
                        else
                        {
                                temp=pop();
                                if(!match(temp, exp[i]))
                                {
                                        printf("Mismatched parentheses are : ");
                                        printf("%c and %c\n",temp,exp[i]);
                                        printf("Invalid expression\n");
                                        return 0;
                                }
                        }
        }
        if(top==-1) /*stack empty*/
        {
                printf("Balanced Parentheses\n");
                 printf("Valid expression\n");
                return 1;
        }
        else
        {
                printf("Left parentheses more than right parentheses\n");
                printf("Invalid expression\n");
                return 0;
        }
        
       

}

int match(char a,char b)
{
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}

void push(char item)
{
        if(top== 99)
        {
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}

char pop()
{
        if(top==-1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        return(stack[top--]);
}