#include<stdio.h>
#include<string.h>
# define SIZE 20
char expr[SIZE],stack1[SIZE+10],post[SIZE+10];
float stack2[SIZE+20];
int top1=-1,top2=-1,p1=0;
int isEmptyOne()
{
    if(top1==-1)
    {
        return 1;
    }
    return 0;
}
int isEmptyTwo()
{
    if(top2==-1)
    {
        return 1;
    }
    return 0;
}
void push1(char x)
{
    top1++;
    stack1[top1]=x;
}
void push2(float x)
{
    top2++;
    stack2[top2]=x;
}
char pop1()
{
    if(isEmptyOne())
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        char val = stack1[top1];
        top1--;
        return val;
    }
}
float pop2()
{
    if(top2==-1)
    {
        printf("\nStack Underflow !! \n\n");
    }
    else
    {
        float val=stack2[top2];
        top2--;
        return val;
    }
}
int priority(char ch)
{
    if(ch=='(')
    {
        return 0;
    }
    if(ch=='-' || ch=='+')
    {
        return 1;
    }
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    return 4;
}
void addToStack(char x)
{
    if(isEmptyOne() || x=='(')
    {
        push1(x);
        return;
    }
    if(x==')')
    {
        while(stack1[top1]!='(')
        {
          char c = pop1();
          post[p1]=c;
          p1++;
        }
        if(stack1[top1]=='(')
        {
            pop1();
            return;
        }
    }
    if(priority(x)>priority(stack1[top1]))
    {
        push1(x);
    }
    else
    {
        while(priority(x)<=priority(stack1[top1]))
        {
           char c = pop1();
           post[p1]=c;
           p1++;

            if(isEmptyOne())
            {
                break;
            }
        }
        push1(x);
    }
}

int isOperator(char x)
{
    switch(x)
    {
        case '+':
        case '-':
        case '*':
        case '/':
                return 1;
    }
    return 0;
}
float scanNum(char x)
{
    switch(x)
    {
        case '0':
                return 0.0;
                break;
        case '1': 
                return 1.0;
                break;
        case '2': 
                return 2.0;
                break;
        case '3': 
                return 3.0;
                break;
        case '4': 
                return 4.0;
                break;
        case '5': 
                return 5.0;
                break;
        case '6': 
                return 6.0;
                break;
        case '7': 
                return 7.0;
                break;
        case '8': 
                return 8.0;
                break;
        case '9': 
                return 9.0;
                break;
    }
}
float compute(float p,char op,float q)
{
    switch(op)
    {
        case '+':
                return(p+q);
                break;
        case '-':
                return(p-q);
                break;
        case '*':
                return(p*q);
                break;
        case '/':
                return(p/q);
                break;   
    }
    return 0;
}

int main()
{
    int len1,len2;
    printf("Enter the infix expression\n");
    scanf("%s",expr);
    len1=strlen(expr);
     for(int i=0;i<len1;i++)
    {
        switch(expr[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
                        addToStack(expr[i]);
                        break;
            default:
                        post[p1]=expr[i];
                        p1++;
        }
    }
     while(!isEmptyOne())
    {
        char c = pop1();
        post[p1]=c;
        p1++;
    }
    post[p1]='\0';
    printf("The postfix expression is : ");
    printf("%s\n",post);

    len2=strlen(post);
    for(int i=0;i<len2;i++)
    {
        if(isOperator(post[i]))
        {
            float a = pop2();
            float b = pop2();
            push2(compute(b,post[i],a));
        }
        else
        {
            float num = scanNum(post[i]);
            push2(num);
        }
    }
    printf("The result of evaluation = %f\n",stack2[top2]);


    return 0;
}