//Program to check whether the string entered is palindrome or not
#include<iostream>
using namespace std;
class Stack{
int data[10];
int top;
public:
    Stack()
    {
    top = -1;
    }
    void Push(int val)
    {
      if(top==9)
            cout<<"Stack overflow";
      else
      {
      top++;
      data[top] = val;
      }

    }
    int Pop()
    {
        if(top==-1)
            cout<<"Stack underflow";
        else
        {
           int n = data[top];
           top--;
           return n;
        }

    }
    void Display()
    {
        if(top==-1)
            cout<<"Stack Underflow";
        else
    {
        for(int i=top;i>=0;i++)
            cout<<data[i]<<endl;
    }
    }
    };
int main()
{
    Stack s1;
    Stack s2;
    int len,d=0;
    char str[30];
    cout<<"Enter a string : ";
    cin>>str;
    for(len=0;str[len] != '\0';len++);
    int c = len-1;
    for(int i=0;i<len/2;i++)
    {
        s1.Push(str[i]);
        s2.Push(str[c--]);
    }
    for(int i=0;i<len/2;i++)
    {
        if(s1.Pop()-32 == s2.Pop()-32)
            d++;
        else
        {
            d=0;
        }
    }
    if(d == len/2)
        cout<<str<<" is a palindrome";
    else
        cout<<str<<" is not a palindrome";

return 0;
}
