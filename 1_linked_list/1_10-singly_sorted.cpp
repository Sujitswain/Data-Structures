#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    
    Node(int d)
    {
        this->data = d;
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

void InsertAtLast(int data, Node* &head, Node* &tail)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void sort(Node* &head)
{
    Node* current = head;
    while(current != NULL)
    {
        Node* nextNode = current->next;
        while(nextNode != NULL)
        {
            if(current->data > nextNode->data)
            {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtLast(100,head,tail);
    InsertAtLast(45,head,tail);
    InsertAtLast(99,head,tail);
    InsertAtLast(89,head,tail);
    InsertAtLast(5,head,tail);
    display(head);

    sort(head);
    display(head);

    return 0;
}