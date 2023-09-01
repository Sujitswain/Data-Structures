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

Node* built_tree(Node* &root)
{
    int data;
    cout<<"\nEnter data: \n";
    cin>>data;
    root = new Node(data); 
    
    if(data == -1)
        return NULL;

    cout<<"\nEnter data for left of "<<data<<": ";
    root->left = built_tree(root->left);

    cout<<"\nEnter data for right of "<<data<<": ";
    root->right = built_tree(root->right);

    return root;
}

// BFS
// using separator for showing levels
void level_Order_Traversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        //purana level complete traverse ho chuka hai
        if(temp == NULL)
        {
            cout<<endl;
            // queue still has some child node
            if(!q.empty())
            {
                q.push(NULL);
            }
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

void reverse_level_order_traversal(Node *root)
{
    queue<Node* > q;
    stack<int> s;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        s.push(temp->data);

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}

// NLR
// print data
// then go left
// then right

void Preorder_Traversal_Iterative(Node* root)
{
    stack<Node* >s;
    s.push(root);

    while(!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        cout<<temp->data<<" ";
        
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }

}

// NLR
void Preorder_Traversal_Recursion(Node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    Preorder_Traversal_Recursion(root->left);
    Preorder_Traversal_Recursion(root->right);
}

// LNR
void Inorder_Traversel_Iteration(Node* root)
{    
    stack<Node* > s;
    Node* temp = root;
    while(!s.empty() || temp != NULL)
    {
        // left 
        if(temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            // node print
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";

            // right
            temp = temp->right;
        }
    }

}

// LNR
void Inorder_Traversal_Recursion(Node* root)
{
    if(root == NULL)
        return;

    Inorder_Traversal_Recursion(root->left);
    cout<<root->data<<" ";
    Inorder_Traversal_Recursion(root->right);
}

// LRN
void Postorder_Traversal_Iteration(Node* root)
{
    stack<Node* > s;
    stack<int> ans; 
    s.push(root);

    while(!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        ans.push(temp->data);

        if(temp->left)
            s.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

// LRN
void Postorder_Traversal_Recursion(Node* root)
{
    if(root == NULL)
        return;

    Postorder_Traversal_Recursion(root->left);
    Postorder_Traversal_Recursion(root->right);
    cout<<root->data<<" ";
}

void built_tree_from_level_order(Node* &root)
{

    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    queue<Node* > q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left Node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right Node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void Count_leaf_node(Node* root, int &count)
{
    if(root == NULL)
        return;

    Count_leaf_node(root->left, count);

    if(root->left == NULL && root->right == NULL)
        count++;

    Count_leaf_node(root->right, count);
}



int main()
{
    /*
        // Node* root = NULL;
        // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
        // built_tree_from_level_order(root);
        // level_Order_Traversel(root);

        // Node* root = NULL;
        // root = built_tree(root);
        
        // //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        // cout<<"\nLevel - Order Traversel : "<<endl;
        // level_Order_Traversel(root);

        // cout<<"\nIn - Order Traversel : "<<endl;
        // Inorder_Traversel(root);
        // cout<<endl;

        // cout<<"\nPre - Order Traversel : "<<endl;
        // Preorder_Traversel(root);
        // cout<<endl;

        // cout<<"\nPost - Order Traversel : "<<endl;
        // Postorder_Traversel(root);
        // cout<<endl;

            int count = 0;
            Count_leaf_node(root, count);
            cout<<count;

    */

    Node* root = NULL;
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
    root = built_tree(root);
    
    cout<<"\nPre - order\n";
    cout<<"Iteration: \n";
    Preorder_Traversal_Iterative(root);
    cout<<"\n Recursion: \n";
    Preorder_Traversal_Recursion(root);

    cout<<"\n\nIn - order\n";
    cout<<"Iteration: \n";
    Inorder_Traversel_Iteration(root);
    cout<<"\n Recursion: \n";
    Inorder_Traversal_Recursion(root);

    cout<<"\n\nPost - order\n";
    cout<<"Iteration: \n";
    Postorder_Traversal_Iteration(root);
    cout<<"\n Recursion: \n";
    Postorder_Traversal_Recursion(root);
    
    return 0;
}