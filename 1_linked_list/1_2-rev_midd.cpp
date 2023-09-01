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

Node* Iterative_reverse(Node* &head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* prev = NULL;
    Node* current = head;
    while(current != NULL)
    {
        Node* next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void Recursion_reverse(Node* &head, Node* prev, Node* current)
{
    if(current == NULL)
    {
        head = prev;
        return;
    }

    Recursion_reverse(head, current, current->next);
    current->next = prev;
}

Node* Recursion_reverse_2(Node* &head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* nextHead = Recursion_reverse_2(head->next);
    head->next->next = head;
    head->next = NULL;

    return nextHead;
}

Node* Recursion(Node* head)
{
    //      method 1
    // Node* prev = NULL;
    // Node* current = head;
    // Recursion_reverse(head, prev, current);
    // return head;

    //      method 2
    head = Recursion_reverse_2(head);
    return head;
}

Node* Middle_list(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    if(head->next->next == NULL)
        return head->next;
    
    Node* slow = head;
    Node* fast = head->next;                        

//          ...........floyd detect middle............

//             1       2       3       4       5
//           slow    fast
          
//             1       2       3       4       5
//                    slow            fast
          
//             1       2       3       4       5
//                            slow           fast
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

        slow = slow->next;
    }
    return slow;
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

    // head = Recursion(head);
    // display(head);
    Node* mid = Middle_list(head);
    cout<<mid->data<<endl;
    return 0;
}