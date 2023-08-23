#include<iostream>
using namespace std;
class Stack
{
        int data[10];
        int top;
    public:
    Stack()
        {
            top = -1;
        }
        void Push(int val)
        {
            if(top == 9)
                cout<<"Stack overflow ";
            else
            {
                top++;
                data[top] = val;
            }
        }
        int Pop()
        {
            if(top == -1)
            {
                cout<<"Stack underflow ";
                return 0;
            }
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
            {
                cout<<"Stack is Empty";
            }
            else
            {
                for(int i = top;i>=0;i--)
                {
                   cout<<data[i]<<endl;
                }

            }

        }

};
int main()
{
    Stack s;
    s.Push(20);
    s.Push(30);
    s.Push(36);
    s.Push(89);
    cout<<"------"<<endl;
    s.Display();
    cout<<"------"<<endl;

    cout<<s.Pop();
return 0;
}
