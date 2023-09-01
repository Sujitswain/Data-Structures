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

void InsertAtHead(int data, Node* &head, Node* &tail)
{
    Node* temp = new Node(data);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

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

void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL)
    {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* add_two_list(Node* first, Node* second)
{
    first = reverse(first);
    second = reverse(second);

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while(first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
            val1 = first->data;
        
        int val2 = 0;
        if(second != NULL)
            val2 = second->data;

        int sum = val1 + val2 + carry;
        InsertAtHead(sum % 10, ansHead, ansTail);

        carry = sum / 10;
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
    }

    return ansHead;
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;
    InsertAtLast(4,head1,tail1);
    InsertAtLast(5,head1,tail1);
    display(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    InsertAtLast(3,head2,tail2);
    InsertAtLast(4,head2,tail2);
    InsertAtLast(5,head2,tail2);
    display(head2);

    Node* ans = add_two_list(head1, head2);
    display(ans);

    return 0;
}