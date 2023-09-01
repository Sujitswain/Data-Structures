#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* random;
    
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
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

Node* solve_method1(Node* head)
{
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;

    while(temp != NULL)
    {
        InsertAtLast(temp->data, cloneHead, cloneTail);
        temp = temp->next;
    }

    unordered_map<Node*, Node*> mapping;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        mapping[originalNode] = cloneNode;
        
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = mapping[originalNode->random];
        
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

Node* solve_method2(Node* head)
{
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    
    while(temp != NULL)
    {
        InsertAtLast(temp->data, cloneHead, cloneTail);
        temp = temp->next;
    }

    Node* originalNode= head;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    temp = head;
    while(temp != NULL)
    {
        if(temp->next != NULL)
        {
            temp->next->random = temp->random ? temp->random->next : temp->random;
            // if(temp->random != NULL)
            //     temp->next->random = temp->random->next;
            // else
            //     temp->next = temp->random;
        }
        temp = temp->next->next;
    }

    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        
        if(originalNode != NULL)
            cloneNode->next = originalNode->next;
        
        cloneNode = cloneNode->next;
    }
    return cloneHead;
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
    display(head);

    // pointing the random nodes
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // cout<<head->data<<" - "<<head->random->data<<endl;
    // cout<<head->next->data<<" - "<<head->next->random->data<<endl;
    // cout<<head->next->next->data<<" - "<<head->next->next->random->data<<endl;
    // cout<<head->next->next->next->data<<" - "<<head->next->next->next->random->data<<endl;
    // cout<<head->next->next->next->next->data<<" - "<<head->next->next->next->next->random->data<<endl<<endl;

    // Node* ans = solve_method1(head);
    // display(ans);
    
    Node* ans = solve_method2(head);
    display(ans);

    cout<<ans->random->data;

    return 0;
}