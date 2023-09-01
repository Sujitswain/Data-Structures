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

Node* solve(Node* &first, Node* &second)
{
    //if one element is present in first
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node* current1 = first;
    Node* next_1 = current1->next;
    Node* current2 = second;

    while(next_1 != NULL && current2 != NULL)
    {
        if(current2->data >= current1->data && current2->data <= next_1->data)
        {
            current1->next = current2;
            
            Node* next_2  = current2->next;
            current2->next = next_1;

            // move to next ie 2 ...if 1 2 3
            current1 = current2;
            current2 = next_2;
        }
        else
        {
            current1 = next_1;
            next_1 = next_1->next;
            
            if(next_1 == NULL)
            {
                current1->next = current2;
            }
        }
        
    }

    return first;
}

Node* merge(Node* &first, Node* &second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    if(first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    InsertAtLast(1,head1,tail1);
    InsertAtLast(3,head1,tail1);
    InsertAtLast(5,head1,tail1);
    display(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    InsertAtLast(2,head2,tail2);
    InsertAtLast(4,head2,tail2);
    InsertAtLast(5,head2,tail2);
    display(head2);

    Node* head = merge(head1, head2);
    display(head);
    return 0;
}