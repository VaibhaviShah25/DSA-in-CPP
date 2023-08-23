#include<iostream>
using namespace std;
/*void push(int arr[],int top,int val);
int pop(int arr[],int top);
void display(int arr[],int top);*/
void push(char arr[],int &top, char val)
{
    if(top==9)
        cout<<"Stack Overflow-insertion impossible "<<endl;
    else
    {
        top++;
        arr[top] = val;
    }
}
int pop(char arr[],int &top)
{
    int val=0;
    if(top==-1)
    {
        return val;
    }
    else
    {
        val = arr[top];
        top--;
    }
    return val;
}
void display(char arr[],int &top)
{
    if(top==-1)
        cout<<"Stack Underflow "<<endl;
    for(int i=top;i>=0;i--)
        cout<<arr[i]<<endl;
}
int main()
{
    int top = -1;
    int i,choice,val,j=0;
    char infix[20],postfix[20],a[10];
    cout<<"Enter infix expression : "<<endl;
    cin>>infix;
    for(i=0;infix[i] != '\0';i++)
    {
        if(infix[i] != '/' && infix[i] != '*' && infix[i] != '+' && infix[i] != '-' && infix[i] != '(' && infix[i] != ')' && infix[i] != '^')
            postfix[j++] = infix[i];
        else
        {
            if(top == -1 || infix[i] == '(' || a[top] == '(' || infix[i] == '^' )
                push(a,top,infix[i]);
            else if(infix[i] == '*'|| infix[i] == '/' || infix[i] == '%')
            {
                if(a[top] == '*' || a[top] == '/' || a[top] == '%' || a[top] == '^')
                {
                    postfix[j++] = pop(a,top);
                }
                push(a,top,infix[i]);

            }
            else if(infix[i] == '+' || infix[i] == '-')

            {
                while(a[top] != '(' && a[top] != -1)
                {
                    postfix[j++] = pop(a,top);
                }
                push(a,top,infix[i]);
            }
            else if(infix[i] == ')')
            {
                while(a[top] != '(')
                {
                    postfix[j++] = pop(a,top);
                }
                pop(a,top);
            }
        }
        }
    while(top != -1)
        postfix[j++] = pop(a,top);
    postfix[j++] = '\0';
    cout<<"Postfix notation is : "<<postfix;
    return 0;
}

