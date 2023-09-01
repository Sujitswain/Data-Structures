#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
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
        cout<<"deleted: "<<val<<endl;
    }
};

void InsertAtTail(int data, Node* &head, Node* &tail)
{
    Node* newNode = new Node(data);
    if(tail == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void reverse(Node* &head)
{
    Node* current = head;
    Node* temp = NULL;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    head = temp->prev;

}

void display(Node* &head)
{
    cout<<"Printing values:"<<endl;
    Node* travel = head;
    while(travel != NULL)
    {
        cout<<travel->data<<" ";
        travel = travel->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtTail(10, head, tail);
    InsertAtTail(20, head, tail);
    InsertAtTail(30, head, tail);
    InsertAtTail(40, head, tail);
    InsertAtTail(50, head, tail);
    display(head);

    reverse(head);
    display(head);
  
    return 0;
}