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

void Remove_Duplicates_Sorted_List(Node* head)
{
    Node* current = head;
    while(current != NULL && current->next != NULL)
    {
        if(current->data == (current->next)->data)
        {
            Node* next = (current->next)->next;
            
            Node* deleteNode = current->next;
            deleteNode->next = NULL;
            delete deleteNode;

            current->next = next;
        }
        else
        {
            current = current->next;
        }
    }
}

void Remove_Duplicates_UnSorted_List(Node* head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while(ptr1 != NULL)
    {
        ptr2 = ptr1;
        while(ptr2->next != NULL)
        {
            if(ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                dup->next = NULL;
                delete dup;
                
                ptr2->next = (ptr2->next)->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void Remove_Duplicates_UnSorted_List2(Node* &head)
{
    if(head == NULL)
        return;
    
    map<int, bool> visited;

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        if(visited[temp->data] == true)
        {
            prev->next = temp->next;
            
            temp->next = NULL;
            delete temp;

            temp = prev->next;
        }
        else
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // InsertAtLast(1,head,tail);
    // InsertAtLast(2,head,tail);
    // InsertAtLast(3,head,tail);
    // InsertAtLast(4,head,tail);
    // InsertAtLast(5,head,tail);
    // InsertAtLast(6,head,tail);

    // Remove_Duplicates_Sorted_List(head);

    InsertAtLast(4,head,tail);
    InsertAtLast(2,head,tail);
    InsertAtLast(5,head,tail);
    InsertAtLast(4,head,tail);
    InsertAtLast(2,head,tail);
    InsertAtLast(2,head,tail);

    Remove_Duplicates_UnSorted_List2(head);
    display(head);

    return 0;
}