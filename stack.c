#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[25];
int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
}

char pop()
{
    char t = stack[top];
    top--;
    return t;
}

/*------------------FOR INFIX TO POSTFIX------------------*/
int isp(char c) // In stack Precedence
{
    if (c == '+' || c == '-')
        return (1);
    if (c == '*' || c == '/' || c == '%')
        return (2);
    if (c == '^')           //3 4 4 3
        return (3);
    if (c == '(')           // isp - 0 ,icp 5
        return (0);
    else
        return (-1);
}

int icp(char c) // incoming precendence
{
    if (c == '+' || c == '-')
        return (1);
    if (c == '*' || c == '/' || c == '%')
        return (2);
    if (c == '^')
        return (4);
    if (c == '(')
        return (5);
    else
        return (-1);
}

/*------------------FOR INFIX TO PREFIX------------------*/

int isp1(char c) // instack precendence
{
    if (c == '+' || c == '-')
        return (1);
    if (c == '*' || c == '/' || c == '%')
        return (2);
    if (c == '^')
        return (4);
    if (c == '(')
        return (0);
    else
        return (-1);
}

int icp1(char c) // Incoming Precedence
{
    if (c == '+' || c == '-')
        return (1);
    if (c == '*' || c == '/' || c == '%')
        return (2);
    if (c == '^')
        return (3);
    if (c == '(')
        return (5);
    else
        return (-1);
}

void infix_postfix(char infix[25])
{
    char postexp[25];
    int p = 0, i = 0; // Indices of infix and postfix arrays
    char tkn;         // Current token
    tkn = infix[i];
    while (tkn != '\0') // Null character '\0' & the process continues till token value is '\0' i.e end of infix expression
    {
        if (isalnum(tkn) != 0) // is alpha : checks for alphabets
        {
            postexp[p] = tkn; // storing alphabet in postexp
            p++;
        }
        else
        {
            if (tkn == '(')
            {
                push('(');
            }
            else
            {
                if (tkn == ')')
                {
                    while ((tkn = pop()) != '(') // popping out all till '('              
                    {
                        postexp[p] = tkn;
                        p++;
                    }
                }
                else 
                {
                    while (top != -1 && isp(stack[top]) >= icp(tkn))
                    {
                        postexp[p] = pop();
                        p++;
                    }
                    push(tkn);
                }
            }
        }
        i++;
        tkn = infix[i];
    }
    while (top != -1)
    {
        postexp[p] = pop();
        p++;
    }
    postexp[p] = '\0';
    printf("Postfix expression = %s\n", postexp);
}

void reverse_infix(char infix[25], char reversed[25])
{
    int len = strlen(infix);
    for (int i = 0; i < len; i++)
    {
        if (infix[len - 1 - i] == '(')
            reversed[i] = ')';
        else if (infix[len - 1 - i] == ')')
            reversed[i] = '(';
        else
            reversed[i] = infix[len - 1 - i];
    }
    reversed[len] = '\0';
}

void infix_prefix(char infix[25])
{
    char prefix[25];
    int p = 0, i = 0;
    char tkn;
    tkn = infix[i];

    while (tkn != '\0')
    {
        if (isalnum(tkn) != 0)
        {
            prefix[p] = tkn;
            p++;
        }
        else
        {
            if (tkn == '(')
            {
                push('(');
            }
            else
            {
                if (tkn == ')')
                {
                    while ((tkn = pop()) != '(')
                    {
                        prefix[p] = tkn;
                        p++;
                    }
                }
                else
                {
                    while (top != -1 && isp1(stack[top]) >= icp1(tkn))
                    {
                        prefix[p] = pop();
                        p++;
                    }
                    push(tkn);
                }
            }
        }
        i++;
        tkn = infix[i];
    }
    while (top != -1)
    {
        prefix[p] = pop();
        p++;
    }

    for (i = 0; i < p / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[p - 1 - i];
        prefix[p - 1 - i] = temp;
    }
     prefix[p] = '\0';
    printf("The Prefix expression is:  %s\n", prefix);
}
int main()
{
    printf("--------------------------------------------\n");
    printf("    Lets perform STACK Operations\n");
    printf("--------------------------------------------\n");
    char infix[25];
    printf("Enter the infix expression : ");
    scanf("%s", infix);
    infix_postfix(infix);
    char revIn[25];
    reverse_infix(infix, revIn);
    infix_prefix(revIn);
    printf("\n--------------------------------------------\n");
    return 0;
}