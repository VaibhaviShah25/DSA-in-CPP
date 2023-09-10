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
void Insert(int value);
void addSorted(int value);
void delfrmbeg();
void delfrmend();
void delfrmpos(int pos);
void sort();
void bsort();
void reversed();
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
        cout<<"Enter 7 - Delete a node from beginning\n";
        cout<<"Enter 8 - Delete a node from end\n";
        cout<<"Enter 9 - Delete a node from given position\n";
        cout<<"Enter 10 - Sort the list\n";
        cout<<"Enter 11 - Reverse the list\n";
        cout<<"Enter 15 - EXIT\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==15)
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
                cout<<"----------------------------------\n";
                cout<<"\tAdded Successfully\n";
                cout<<"----------------------------------\n";
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
                break;
            case 7:
                delfrmbeg();
                break;
            case 8:
                delfrmend();
                break;
            case 9:
                int pos;
                cout<<"Enter position to be deleted"<<endl;
                cin>>pos;
                delfrmpos(pos);
                break;
            case 10:
                bsort();
                display();
                break;
            case 11:
                reversed();
                display();
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
    int c=0,d=0;
    if(start == NULL)
        cout<<"Element not found";
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            c++;
            if(ptr->data == value)
            {
                d++;
               cout<<value<<" found at "<<c<<endl;
               break;
            }
            else
                ptr = ptr->next;

        }
        if(d == 0)
            cout<<"Element not found"<<endl;
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
        cout<<"----------------------------------\n";
        cout<<"\tAdded Successfully\n";
        cout<<"----------------------------------\n";
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
    cout<<"----------------------------------\n";
    cout<<"\tAdded Successfully\n";
    cout<<"----------------------------------\n";
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
            {
                ptr = ptr->next;
            }
    }
    if(ptr == NULL)
    {
        addNode(value);
    }
    cout<<"----------------------------------\n";
    cout<<"\tAdded Successfully\n";
    cout<<"----------------------------------\n";
}

void Insert(int value)
{
    int d=0,c=0;
    Node *temp, *ptr;
    temp = new Node;
    ptr = start;
    temp->data = value;
    if(start == NULL)
    {
        start = temp;
        temp->next = NULL;
        cout<<temp->data<<endl;
    }
    else
    {
        while(ptr != NULL)
        {
            //d++;
            if(ptr->data <= value && ptr->next->data >= value)
            {
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
            else
            {
                //c++;
                ptr = ptr->next;
            }

        }
        if(d == c)
        {
            ptr->next = temp;
            temp->next = NULL;
        }
        cout<<"----------------------------------\n";
        cout<<"\tAdded Successfully\n";
        cout<<"----------------------------------\n";
    }
}
void delfrmbeg()
{

    Node *ptr;
    if(start == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        ptr = start;
        start = start->next;
        delete ptr;
        cout<<"----------------------------------\n";
        cout<<"\tDeleted Successfully\n";
        cout<<"----------------------------------\n";
    }
}
void delfrmend()
{
    Node *ptr,*temp;
    ptr = start;
    if(start == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(ptr->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        while(ptr->next->next != NULL)
        {
           ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL;
        cout<<"----------------------------------\n";
        cout<<"\tDeleted Successfully\n";
        cout<<"----------------------------------\n";

    }
}
void delfrmpos(int pos)
{
    Node *ptr,*temp;
    ptr = start;
    if(start == NULL)
        cout<<"List is empty"<<endl;
    else if(ptr->next == NULL)
        delfrmend();
    else
    {
        for(int i=1;i<= pos-2;i++)
        {
            ptr=ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        cout<<"----------------------------------\n";
        cout<<"\tDeleted Successfully\n";
        cout<<"----------------------------------\n";

    }
}
void sort()
{
    Node *ptr,*i,*j;
    int temp;
    ptr = start;
    for(i=ptr;i->next != NULL;i=i->next)
    {
        for(j=i->next;j != NULL; j=j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void bsort()
{
    Node *ptr,*i,*j;
    int temp;
    ptr = start;
    for(i=ptr;i != NULL;i=i->next)
    {
        for(j=start; j->next != NULL; j=j->next)
        {
            if(j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}
void reversed()
{
    Node *ptr,*newptr;
    newptr = NULL;
    while(start != NULL)
    {
        ptr = start;
        start = start->next;
        ptr->next = newptr;
        newptr = ptr;
    }
    start = newptr;

}
