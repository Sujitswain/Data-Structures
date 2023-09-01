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

Node* k_group(Node* head, int k)
{
    if(head == NULL)
        return NULL;

    // step 1: reverse 1st k node
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int c = 0;

    while (c < k && current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        c++;
    }

    // step 2: recursion
    if(next != NULL)
    {
        head->next = k_group(next, k);
    }

    // step 3:
    return prev;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtLast(1,head,tail);
    InsertAtLast(2,head,tail);
    InsertAtLast(3,head,tail);
    InsertAtLast(4,head,tail);
    InsertAtLast(5,head,tail);
    InsertAtLast(6,head,tail);
    display(head);

    int k = 4;
    head = k_group(head,k);
    display(head);

    return 0;
}