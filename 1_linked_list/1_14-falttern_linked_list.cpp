#include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
        int data;
        Node* right;
        Node* down;

        Node(int d)
        {
            this->data = d;
            this->right = NULL;
            this->down = NULL;
        }
};

Node* InsertAtLast(int data, Node* &head, Node* &tail)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->down = newNode;
        tail = newNode;
    }
    return head;
}

void display_parent_child(Node* head, Node* tail)
{
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2 != NULL)
    {
        temp1 = temp2;
        while(temp1 != NULL)
        {
            cout<<temp1->data<<" ";
            temp1 = temp1->down;
        }
        cout<<endl;
        temp2 = temp2->right;
    }
    cout<<endl<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl<<endl;
}

void display(Node* head, Node* tail)
{
    Node* temp1 = head;
    while(temp1 != NULL)
    {
        cout<<temp1->data<<" ";
        temp1 = temp1->down;
    }
}

Node* merge(Node* first, Node* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;

    Node* ans = new Node(-1);
    Node* temp = ans;
    while(first != NULL && second != NULL)
    {
        if(first->data < second->data)
        {
            temp->down = first;
            temp = first;
            first = first->down;
        }
        else
        {
            temp->down = second;
            temp = second;
            second = second->down;
        }
    }

    while(first != NULL)
    {
        temp->down = first;
        temp = first;
        first = first->down;
    }

    while(second != NULL)
    {
        temp->down = second;
        temp = second;
        second = second->down;
    }
    return ans->down;
}

Node* Faltter_a_linked_list(Node* &head)
{
    if(head == NULL || head->right == NULL)
        return head;

    Node* nextNode = Faltter_a_linked_list(head->right);
    return merge(head, nextNode);
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    head = InsertAtLast(5, head, tail);
    head = InsertAtLast(7, head, tail);
    head = InsertAtLast(8, head, tail);
    head = InsertAtLast(30, head, tail);

    head->right = InsertAtLast(10, head->right, tail);
    head->right = InsertAtLast(20, head->right, tail);
    
    head->right->right = InsertAtLast(19, head->right->right, tail);
    head->right->right = InsertAtLast(22, head->right->right, tail);
    head->right->right = InsertAtLast(50, head->right->right, tail);

    head->right->right->right = InsertAtLast(28, head->right->right->right, tail);
    head->right->right->right = InsertAtLast(35, head->right->right->right, tail);
    head->right->right->right = InsertAtLast(40, head->right->right->right, tail);
    head->right->right->right = InsertAtLast(45, head->right->right->right, tail);
    
    display_parent_child(head, tail);

    head = Faltter_a_linked_list(head);    

    display(head, tail);

    return 0;
}