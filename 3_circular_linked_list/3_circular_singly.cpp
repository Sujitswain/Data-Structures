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

void InsertNode(Node* &tail, int element, int value)
{
    Node* newNode = new Node(value);
 
    if(tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        Node* current = tail;
        while(current->data != element)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void DeleteNode(Node* &tail, int element)
{
    if(tail == NULL)
    {
        cout<<"empty list";
        return;
    }
    else
    {
        Node* prev = tail;
        Node* current = prev->next;

        while(current->data != element)
        {
            prev = current;
            current = current->next;
        }

        // if only 1 element exists
        if(current == prev)
        {
            tail = NULL;
        }
        
        // >= 2
        if(tail == current)
        {
            tail = prev;
        }
        
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void dispaly(Node* tail)
{
    Node* temp = tail;

    if(tail == NULL)
    {
        cout<<"empty list";
        return;
    }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    
    cout<<endl;
}

int main()
{
    Node* tail = NULL;

    InsertNode(tail,5,3);
    dispaly(tail);

    InsertNode(tail,3,5);
    dispaly(tail);

    InsertNode(tail,5,7);
    dispaly(tail);

    InsertNode(tail,7,9);
    dispaly(tail);

    InsertNode(tail,5,6);
    dispaly(tail);

    InsertNode(tail,9,10);
    dispaly(tail);

    InsertNode(tail,3,4);
    dispaly(tail);

    DeleteNode(tail,6);
    dispaly(tail);

    return 0;
}