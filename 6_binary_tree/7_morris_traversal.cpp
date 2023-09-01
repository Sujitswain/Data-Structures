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

Node* build_binary_tree(Node* &root)
{
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    cout<<"\nEnter data for left of "<<root->data<<": "<<endl;
    root->left = build_binary_tree(root->left);
    
    cout<<"\nEnter data for right of "<<root->data<<": "<<endl;
    root->right = build_binary_tree(root->right);

    return root;
}

void level_order_traversal(Node* root)
{
    queue<Node* > q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
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

// space complexity o(1);
// time complexity o(n);
void morris_traversal(Node* root)
{
    Node* current = root;
    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout<<current->data<<" ";
            current = current->right;
        }
        else
        {
            Node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if(predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }

        }
    }
}


// traverse and make node (extra space)
// recursion - (NULL<--root--left_st--right_st) space:o(n) 
void flattern(Node* &root)
{
    Node* current = root;
    while(current != NULL)
    {
        if(current->left)
        {
            Node* predecessor = current->left;
            while(predecessor->right != NULL)
                predecessor = predecessor->right;
            
            predecessor->right = current->right;
            current->right = current->left;
            
            // making left as null;
            current->left = NULL;
        }
        current = current->right;
    }
}

int main()
{
    Node* root = NULL;

    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    
    /*
        // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1
        root = build_binary_tree(root);
        level_order_traversal(root);
        morris_traversal(root);
    */
    root = build_binary_tree(root);
    level_order_traversal(root);
    flattern(root);
    level_order_traversal(root);
    return 0;
}