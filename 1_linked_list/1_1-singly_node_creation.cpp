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
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Node deleted: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head, Node* &tail, int data)
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
        head = newNode;
    }
}

void InsertAtTail(Node* &head, Node* &tail, int data)
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

void InsertAtPosition(int pos, int data, Node* &head, Node* &tail)
{
    if(pos == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int c = 1;
    while (c < pos-1)
    {
        temp = temp->next;
        c++;
        if(temp == NULL)
        {
            cout<<"cannot insert"<<endl;
            return;
        }
    }

    if(temp->next == NULL)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int pos, Node* &head, Node* &tail)
{
    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* prev = NULL;
        Node* current = head;

        int c = 1;
        while (c < pos)
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
        current->next = NULL;
        delete current;
    }
}

void search(int value, Node* &head)
{
    Node* travel = head;
    int c = 1;

    while(travel != NULL)
    {
        if(travel->data == value)
        {
            cout<<"value found at: "<<c;
            return;
        }
        c++;
        travel = travel->next;
    }
    cout<<"Value not found";
}

void display(Node* &head, Node* &tail)
{
    cout<<"Printing values:"<<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
   
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    display(head,tail);


    InsertAtTail(head, tail, 30);
    InsertAtTail(head, tail, 40);
    display(head, tail);


    InsertAtPosition(1, 110, head, tail);
    InsertAtPosition(6, 50, head, tail);
    display(head, tail);


    
    deleteNode(1, head, tail);
    display(head, tail);


    deleteNode(5, head, tail);
    display(head, tail);


    deleteNode(3, head, tail);
    display(head, tail);


    search(110, head);


    return 0;
}