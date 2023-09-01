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
        cout<<"Deleted: "<<val<<endl;
    }
};
Node* head = NULL;


void push(int data)
{
    Node* newNode = new Node(data);

    if(head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void pop()
{
    if(head == NULL)
    {
        cout<<"Stack empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    
    temp->next = NULL;
    delete temp;
}

void isEmpty()
{
    if(head != NULL)
        cout<<"Stack is not empty";
    else
        cout<<"Stack empty";
}

void display()
{
    if(head == NULL)
    {
        cout<<"Empty Stack"<<endl<<endl;
    }
    else
    {
        cout<<endl<<"Top element: "<<head->data;
        cout<<endl<<"Printing Values: ";
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();

    pop();
    pop();
    pop();
    pop();
    pop();

    display();

    isEmpty();

    return 0;
}