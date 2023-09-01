#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->left = this->right = NULL;
        }
};

Node* Insert_BST(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
        root->left = Insert_BST(root->left, data);
    else
        root->right = Insert_BST(root->right, data);
    
    return root;
}

void build_BST(Node* &root)
{
    int data;
    cout<<"Enter the data for BST:\n";
    cin>>data;

    while(data != -1)
    {
        root = Insert_BST(root, data);
        cin>>data;
    }
}

void level_order_traversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<"\n";
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void valid_BST(Node* root)
{
        
}

int main()
{
    Node* root = NULL;
    build_BST(root);
    level_order_traversal(root);

    return 0;
}