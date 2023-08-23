#include<iostream>
using namespace std;
const int MAX=10;
void enque(int que[], int &front, int &rear, int value)
{
    if(front == 0 && rear == MAX - 1 || front == rear + 1)
        cout<<"Queue is full- Queue overflow"<<endl;
    else if(front == -1)
    {
        front = rear = 0;
        que[0] = value;
    }
    else
    {
        if(front != 0 && rear == MAX)
        {
            rear = MAX % rear;
            que[rear] = value;
        }
        else
        {
            rear++;
            que[rear] = value;
        }

    }

}
int deque(int que[], int &front, int &rear)

{   int val = 0;
    if(front == -1)
        cout<<"Deletion not possible-Queue Underflow"<<endl;
    else if(front == rear)
    {
        val = que[front];
        front = rear = -1;
    }

    else
    {
        val = que[front];
        if(front == MAX-1)
            front = 0;
        else
            front++;
    }
    return val;
}
void display(int que[],int &front,int &rear)
{
    if(front == rear)
        cout<<"No element found"<<endl;
    else
    {
        if(front > rear)
        {
            for(int i=front;i<= MAX-1;i++)
                cout<<que[i]<<"\t";
            for(int i=0;i<=rear;i++)
                cout<<que[i]<<"\t";
        }
        else
        {
           for(int i=front;i<=rear;i++)
                cout<<que[i]<<"\t";
        }

    }
    cout<<endl;
}
int main()
{
    int p,i,front = -1, rear = -1,time,timeq,val = 1,num,c=0,comp = 0,n;
    cout<<"How many processes are there : ";
    cin>>p;
    int pro[MAX];
    for(i=0;i<p;i++)
    {
        cout<<"Enter time "<<i+1<<" : ";
        cin>>time;
        enque(pro,front,rear,time);
    }
    cout<<endl<<"Enter time quantum : ";
    cin>>timeq;
    //display(pro,front,rear);
    while(front != -1)
    {
        comp++;
        num = deque(pro,front,rear);
        if(num <= timeq)
        {
            cout<<"Process Completed : "<<comp<<endl;
        }
        else
        {
            //display(pro,front,rear);
            //cout<<"----------------------------------------"<<endl;
            //cout<<"Process executed for "<<timeq<<" sec and added back to queue"<<endl;
            enque(pro,front,rear,num-timeq);
        }

    }
return 0;
}
