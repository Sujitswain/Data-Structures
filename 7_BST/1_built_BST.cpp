#include<bits/stdc++.h>
using namespace std;

/*
    inorder is always sorted in BST
*/

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

Node* InsertIntoBST(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(root->data < data)
        root->right = InsertIntoBST(root->right, data);
    else
        root->left = InsertIntoBST(root->left, data);

    return root;
}

void build_BST(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = InsertIntoBST(root, data);
        cin>>data;
    }   
}

void level_order_traversal(Node* root)
{
    if(root == NULL)
        return;

    queue<Node* >q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
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

// t - (0 log n) else o(n)
// s - o(n)
bool search_BST_Recursive(Node* root, int target)
{
    if(root == NULL)
        return false;

    if(root->data == target)
        return true;

    if(root->data > target)
        search_BST_Recursive(root->left, target);
    else
        search_BST_Recursive(root->right, target);
}

bool search_BST_Iterative(Node* root, int target)
{
    Node* temp = root;
    while(temp != NULL)
    {
        if(temp->data == target)
            return true;

        if(temp->data > target)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

Node* minValue(Node* root)
{
    Node* temp = root;
    while(temp != NULL)
        temp = temp->left;
    
    return temp;
}

Node* maxValue(Node* root)
{
    Node* temp = root;
    while(temp != NULL)
        temp = temp->right;
    
    return temp;
}

Node* delete_in_BST(Node* &root, int target)
{
    if(root == NULL)
        return root;

    if(root->data == target)
    {
        if(root->left == NULL && root->right == NULL)
        {    
            delete root;
            return NULL;
        }
        
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // either min value in right sub-tree
        // or max value in left sub-tree
        if(root->left != NULL && root->right != NULL)
        {
            int min1 = minValue(root->right)->data;
            root->data = min1;
            root->right = delete_in_BST(root->right, min1);
            return root;
        }
    }
    else if(root->data > target)
    {
        root->left = delete_in_BST(root->left, target);
        return root;
    }
    else
    {
        root->right = delete_in_BST(root->right, target);
        return root;
    }
}

int main()
{
    Node* root = NULL;
    
    // 100 50 25 70 60 110 120 115

    /*
        cout<<search_BST(root, 23);
        cout<<search_BST_Iterative(root, 21);
    */

    cout<<"Enter the elements for BST: \n";
    build_BST(root);
    level_order_traversal(root);
    
    delete_in_BST(root, 25);
    
    level_order_traversal(root);
    return 0;
}