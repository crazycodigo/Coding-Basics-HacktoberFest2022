#include <iostream>

using namespace std;

#define size 5
int queue[size];
int front =-1;
int rear=-1;

//Enqueue function
void enqueue(int val)
{
    if((rear+1)%size==front)
    {
        cout<<"Overflow condition\n";
    }
    else if((front==-1) && (rear==-1))
    {
        front=0;
        rear=0;
        queue[rear]=val;
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=val;
    }
}

//Dequeue function
void dequeue()
{
    if((front==-1)&&(rear==-1))
    {
        cout<<"Underflow condition\n";
    }
    else if(front==rear)
    {
        cout<<"The deleted element is "<<queue[front]<<'\n';
        front=-1;
        rear=-1;
    }
    else{
        cout<<"The deleted element is "<<queue[front]<<'\n';
        front=(front+1)%size;
    }
}

//traversal function
void traversal()
{
    int i;
    i=front;
    if((front==-1)&&(rear==-1))
    {
        cout<<"Queue is empty"<<'\n';
    }
    else{
        cout<<"Displaying the elements of queue\n";
        while(i<=rear)
        {
            cout<<queue[i]<<'\n';
            i=(i+1)%size;
        }
        cout<<'\n';
    }
}

//Main function
int main()
{
    int val,ch;
    cout<<"Enter the first element to create the queue\n";
    cin>>val;
    enqueue(val);
    // traversal();
    do
    {
        cout<<"Enter your choice\n";
        cout<<"0.exit\n1.Inserting an element\n2.Deleteing an element\n3.Displaying the queue\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the element to be inserted\n";
                cin>>val;
                enqueue(val);
                // traversal();
                break;
            }
            case 2:
            {
                dequeue();
                // traversal();
                break;
            }
            case 3:
            {
                traversal();
                break;
            }
        }
    }
    while(ch!=0);
    {
        return 0;
    }
}

//Contributing By grraghav120 (Raghav Garg)