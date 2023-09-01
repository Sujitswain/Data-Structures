#include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
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

void display(Node* head, Node* tail)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl<<endl;

}

Node* find_mid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right, Node* &tail)
{
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next =right;
            temp = right;
            tail = right;
            right = right->next;   
        }
    }

    while(left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL)
    {
        temp->next =right;
        temp = right;
        tail = right;
        right = right->next;   
        
    }

    return ans->next;
}

Node* merge_sort(Node* &head,Node* &tail)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* mid = find_mid(head);

    // break into two
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = merge_sort(left, tail);
    right = merge_sort(right, tail);

    // merge
    Node* res = merge(left, right, tail); 
    return res;
} 

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtLast(5, head, tail);
    InsertAtLast(3, head, tail);
    InsertAtLast(1, head, tail);
    InsertAtLast(2, head, tail);
    InsertAtLast(4, head, tail);
    InsertAtLast(9, head, tail);
    InsertAtLast(6, head, tail);

    head = merge_sort(head, tail);

    display(head, tail);
    return 0;
}