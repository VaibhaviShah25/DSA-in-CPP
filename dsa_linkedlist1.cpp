//Program to perform basic functions on Linked List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;//self refrencial member
};
Node *start;
void addNode(int value);
void display();
void Search(int value);
void addBeg(int value);
void addPos(int value,int pos);
void addSorted(int value);
int main()
{
    start = NULL;
    int num,i,val,ch,pos;
    char a;
    while(1)
    {

        cout<<"\nEnter 1 - Add a Node\n";
        cout<<"Enter 2 - Add a Node at beginning\n";
        cout<<"Enter 3 - Add a Node at a position\n";
        cout<<"Enter 4 - Search a Node\n";
        cout<<"Enter 5 - Display\n";
        cout<<"Enter 6 - Add in sorted order\n";
        cout<<"Enter 10 - EXIT\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==10)
            break;
        else
        {

            switch(ch)
            {
            case 1:
                cout<<"Enter how many nodes you want to add : ";
                cin>>num;
                cout<<"Enter numbers : ";
                for(i=1;i<=num;i++)
                {
                    cin>>val;
                    addNode(val);
                }
                break;
            case 2:
                cout<<"Enter the value to be added : ";
                cin>>val;
                addBeg(val);
                break;
            case 3:
                cout<<"Enter the position and value to be added : ";
                cin>>pos>>val;
                addPos(val,pos);
                break;
            case 4:
                cout<<"Enter the element to be searched : ";
                cin>>val;
                Search(val);
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Enter the value to be added : ";
                cin>>val;
                addSorted(val);

            }
        }
    }

return 0;
}

void addNode(int value)
{
    Node *temp,*ptr;
    temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void display()
{
    Node *temp,*ptr;
    if(start == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }
}
void Search(int value)
{
    Node *temp,*ptr;
    if(start == NULL)
        cout<<"Element not found";
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            if(ptr->data == value)
            {
               cout<<value<<" found at "<<ptr;
               break;
            }
            else
                ptr = ptr->next;

        }
        if(ptr == NULL)
            cout<<"Element not found";
    }
}
void addBeg(int value)
{
    Node *ptr, *temp;
    temp = new Node;
    temp->data = value;
    if(start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    else
    {
       temp->next = start;
        start = temp;
    }
}
void addPos(int value,int pos)
{
    Node *ptr,*temp;
    temp = new Node;
    ptr = start;
    temp->data = value;
    for(int i=1;i<=pos-2;i++)
    {
        if(ptr->next == NULL)
        {
            cout<<"Invalid Position";
            return;
        }
        else
            ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void addSorted(int value)
{
    Node *temp, *ptr;
    temp = new Node;
    ptr = start;
    temp->data = value;
    while(ptr != NULL)
    {
        if(ptr->data <= value && ptr->next->data >= value)
        {
            temp->next = ptr->next;
            ptr->next = temp;
            return;
        }
        else
            ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        addNode(value);
    }
}
