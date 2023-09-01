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

bool detect_Loop(Node* head)
{
    if(head == NULL)
        return false;
    
    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL)
    {
        if(visited[temp] == true)
            return true;
            
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floyds_detect_loop(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if(slow == fast)
        {
            cout<<"cycle at present at: "<<slow->data<<endl;
            return slow;
        }
    }

    return NULL;
}

Node* find_Start_Of_Loop(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* intersection = floyds_detect_loop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    
    return slow;
}

void Remove_Loop(Node* head)
{
    if(head == NULL)
        return;

    Node* start = find_Start_Of_Loop(head);
    Node* temp = start;
    while(temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    InsertAtLast(7,head,tail);
    
    // making it as a cycle
    tail->next = head->next;
    
    // Normal method ::
    // if(detect_Loop)
    //     cout<<"Normal method: loop is present"<<endl;
    
    // floyds method ::
    // floyds_detect_loop(head);

    // finding starting element of loop ::
    Node* start = find_Start_Of_Loop(head);
    cout<<start->data<<endl;

    Remove_Loop(head);

    display(head);

}