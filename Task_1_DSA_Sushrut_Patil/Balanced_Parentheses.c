#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 20
int stack[Max];
char str[Max];
int top = -1;

void push(char item)
{
  if (top == Max - 1){
    printf("\nStack is Full\n");
    return;
  } 
  top++;
  stack[top] = item;
}
void pop()
{
  if (top == -1)
  {
    printf("\nstack is empty\n");
  }
  top--;
}

// void PrintArray()
// {

//     printf("\nAll Items in Stack : ");
//     for (int i = 0; i <= top; i++)
//     {
//         printf("\t%d", stack[i]);
//     }
//     printf("\n");
// }

void checker(char arr[])
{
  int i;
  while (arr[i] != '\0')
  {
    if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
    {
      push(arr[i]);
    }
    else if (arr[i] == ')' && stack[top] == '(')
    {
      pop();
    }
    else if (arr[i] == '}' && stack[top] == '{')
    {
      pop();
    }
    else if (arr[i] == ']' && stack[top] == '[')
    {
      pop();
    }
    i++;
    // PrintArray();
  }
}


int main()
{
  printf("Enter Expression : ");
  gets(str);
  checker(str);
  if (top == -1)
  {
    printf("\nExpression is Balanced\n");
  }
  else
  {
    printf("\nExpression is Not Balanced\n");
  }

  return 0;
}