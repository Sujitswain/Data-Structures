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

void sort1(Node* &head)
{
    Node* temp = head;
    int c_0 = 0, c_1 = 0, c_2 = 0;
    while (temp != NULL)
    {
        if(temp->data == 0)
            c_0++;
        else if(temp->data == 1)
            c_1++;
        else if(temp->data == 2)
            c_2++;

        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if(c_0 != 0)
        {
            temp->data = 0;
            c_0--;
        }   
        else if(c_1 != 0)
        {
            temp->data = 1;
            c_1--;
        }   
        else if(c_2 != 0)
        {
            temp->data = 2;
            c_2--;
        }  
        temp = temp->next; 
    }

}

void InsertAtTail(Node* &tail, Node* curr)
{
    tail->next = curr;
    tail = curr;
}

void sort2(Node* &head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* temp = head;
    while(temp != NULL)
    {
        int val = temp->data;
        if(val == 0)
            InsertAtTail(zeroTail, temp);
        else if(val == 1)
            InsertAtTail(oneTail, temp);
        else if(val == 2)
            InsertAtTail(twoTail, temp);
        
        temp = temp->next;
    }

    // merge
    if(oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    
    // delete
    zeroHead->next = NULL;
    delete zeroHead;
    oneHead->next = NULL;
    delete oneHead;
    twoHead->next = NULL;
    delete twoHead;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtLast(1,head,tail);
    InsertAtLast(0,head,tail);
    InsertAtLast(1,head,tail);
    InsertAtLast(2,head,tail);
    InsertAtLast(2,head,tail);

    sort2(head);

    display(head);
    return 0;
}