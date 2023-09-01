#include<bits/stdc++.h>
using namespace std;

/*
    preorder : NLR
    inorder : LNR
    postorder : LRN

    in =  {3, 1, 4, 0, 5, 2}
    pre = {0, 1, 3, 4, 2, 5}

                      0
    in    {3, 1, 4}       {5, 2}
    pre   {1, 3, 4}       {2, 5}

             1               2

        {3}     {4}      {5}     X

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


// create mapping for inorder
void createMappingInorder(int in[], map<int, int> &nodeToIndex, int n)
{
    for(int i=0; i<n; i++)
        nodeToIndex[in[i]] = i;
}



Node* solve_pre_in_order_tree(int pre[], int in[], int &preOrderIndex, 
                int inOrderStart, int inOrderEnd, int n, map<int, int> nodeToIndex )
{
    if(preOrderIndex >= n || inOrderStart > inOrderEnd)
        return NULL;

    int element = pre[preOrderIndex++];
    Node* root = new Node(element);

    int position = nodeToIndex[element];
    root->left =  solve_pre_in_order_tree(pre, in, preOrderIndex, inOrderStart, position-1, n, nodeToIndex);
    root->right = solve_pre_in_order_tree(pre, in, preOrderIndex, position+1, inOrderEnd, n, nodeToIndex);
    
    return root;
}

// qestion 1
Node* Problem_1_tree_pre_in(Node* &root)
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(pre) / sizeof(pre[0]);
    int preOrderIndex = 0;

    map<int, int> nodeToIndex;
    createMappingInorder(in, nodeToIndex, n);

    root = solve_pre_in_order_tree(pre, in, preOrderIndex, 0, n-1, n, nodeToIndex);

    return root;
}



Node* solve_post_in_order_tree(int post[], int in[], int &postOrderIndex, 
                int inOrderStart, int inOrderEnd, int n, map<int, int> nodeToIndex )
{
    if(postOrderIndex < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int element = post[postOrderIndex--];
    Node* root = new Node(element);

    int position = nodeToIndex[element];
    root->right = solve_post_in_order_tree(post, in, postOrderIndex, position+1, inOrderEnd, n, nodeToIndex);
    root->left =  solve_post_in_order_tree(post, in, postOrderIndex, inOrderStart, position-1, n, nodeToIndex);
    
    return root;
}

// question 2
Node* Problem_2_tree_post_in(Node* &root)
{
    int in[] =   {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(post) / sizeof(post[0]);
    int postOrderIndex = n-1;

    map<int, int> nodeToIndex;
    createMappingInorder(in, nodeToIndex, n);

    root = solve_post_in_order_tree(post, in, postOrderIndex, 0, n-1, n, nodeToIndex);

    return root;
}


int main()
{
    Node* root = NULL;

    root = Problem_1_tree_pre_in(root);
    level_order_traversal(root);

    root = Problem_2_tree_post_in(root);
    level_order_traversal(root);

    return 0;
}