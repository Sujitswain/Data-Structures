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

void InsertAtHead(int data, Node* &head, Node* &tail)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

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

void InsertAtPos(int data, int pos, Node* &head, Node* &tail)
{
    if(pos == 1)
    {
        InsertAtHead(data, head, tail);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
        if(temp == NULL)
        {
            cout<<"cannot Insert"<<endl;
            return;
        }
    }
    
    if(temp->next == NULL)
    {
        InsertAtTail(data,head,tail);
        return;
    }
    
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    (temp->next)->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAnyPos(int pos, Node* &head, Node* &tail)
{
    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;

        (temp->next)->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* prev = NULL;
        
        int c = 1;
        while(c < pos)
        {
            prev = current;
            current = current->next;
            c++;
        }

        prev->next = current->next;
        if(current->next == NULL)
        {
            tail = prev;
        }

        current->prev = NULL;
        current->next = NULL;
        delete current;
    }
}

void display(Node* &head, Node* &tail)
{
    cout<<"Printing values:"<<endl;
    Node* travel = head;
    while(travel != NULL)
    {
        cout<<travel->data<<" ";
        travel = travel->next;
    }
    cout<<endl;
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(10, head, tail);
    InsertAtHead(20, head, tail);
    display(head,tail);

    
    InsertAtTail(30, head, tail);
    InsertAtTail(40, head, tail);
    display(head,tail);


    InsertAtPos(100,1,head,tail);
    InsertAtPos(120,6,head,tail);
    display(head,tail);



    deleteAnyPos(1,head,tail);
    display(head,tail);


    deleteAnyPos(5,head,tail);
    display(head,tail);


    deleteAnyPos(3,head,tail);
    display(head,tail);


    return 0;
}