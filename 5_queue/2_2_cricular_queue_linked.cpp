#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
            {
                delete next;
                this->next = NULL;
            }
            cout<<"Value deleted: "<<val<<endl;
        }
};

void push(int data, Node* &front, Node* &rear)
{
    Node* newNode = new Node(data);
    if(front == NULL)
    {
        newNode->next = newNode;
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void pop(Node* &front, Node* &rear)
{
    if(front == NULL)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    else
    {
        Node* temp = front;
        front = front->next;
        
        temp->next = NULL;
        delete temp;

        if(front == NULL)
            front = rear = NULL;
    }
}

void display(Node* front, Node* rear)
{
    Node* temp = front;
    if(front == NULL)
    {
        cout<<"Empty Queue";
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<"Front: "<<front->data;
    cout<<endl<<"Rear: "<<rear->data<<endl<<endl;
}

int main()
{
    Node* front = NULL;
    Node* rear = NULL;

    push(10, front, rear);
    push(20, front, rear);
    push(30, front, rear);
    push(40, front, rear);
    push(50, front, rear);

    display(front, rear);
    
    pop(front, rear);
    pop(front, rear);
    pop(front, rear);

    pop(front, rear);
    display(front, rear);
    pop(front, rear);
    display(front, rear);
    

    return 0;
}