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
        cout<<"value Deleted : "<<val;
    }
};

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

void display(Node* head, Node* tail)
{
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

bool palindrome_method1(Node* head)
{
    vector<int> v;
    Node* temp = head;

    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0;
    int end = v.size()-1; 
    while(start <= end)
    {
        if(v[start] != v[end])
            return false;
        start++;
        end--;
    }
    return true;
}

Node* find_Middle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

bool palindrome_method2(Node* head)
{
    Node* middle = find_Middle(head);

    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data)
            return false;
        
        head1 = head1->next;
        head2 = head2->next;
    }

    // not necessary
    middle->next = reverse(temp);

    return true;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    display(head, tail);

    cout<<palindrome_method2(head);
}