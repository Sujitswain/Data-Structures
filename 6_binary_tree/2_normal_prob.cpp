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

Node* built_binary_tree(Node* &root)
{
    int data;
    cout<<"\nEnter data: \n";
    cin>>data;
    root = new Node(data); 
    
    if(data == -1)
        return NULL;

    cout<<"\nEnter data for left of "<<data<<": ";
    root->left = built_binary_tree(root->left);

    cout<<"\nEnter data for right of "<<data<<": ";
    root->right = built_binary_tree(root->right);

    return root;
}

void level_order_traversal(Node* root)
{
    queue<Node* > q;
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

// longest path between root node and the leaf node
int Height_of_Binary_tree_iteration(Node* root)
{
    if(root == NULL)
        return 0;

    queue<Node* > q;
    q.push(root);
    int height = 0;

    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
        height++;
    }

    return height;
}

int Height_of_Binary_tree_recursion(Node* root)
{
    if(root == NULL)
        return 0;

    int left = Height_of_Binary_tree_recursion(root->left);
    int right = Height_of_Binary_tree_recursion(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

// (longest path between any two ending nodes)
// either in left sub - tree
// either in right sub - tree
// or combo
// not optimized
int diameter_of_binary_tree(Node* root)
{
    if(root == NULL)
        return 0;

    int option_1 = diameter_of_binary_tree(root->left);
    int option_2 = diameter_of_binary_tree(root->right);
    int option_3 = Height_of_Binary_tree_recursion(root->left) + Height_of_Binary_tree_recursion(root->right) + 1 ;
    
    int ans = max(option_1, max(option_2, option_3));
    return ans;
}

// optimized way
pair<int, int> diameter_optimized(Node* root)
{
    if(root == NULL)
    {
        // first = Diameter;
        // second = Height;
                                //   d  h 
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameter_optimized(root->left);
    pair<int, int> right = diameter_optimized(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first =  max(option1, max(option2, option3)); // diameter
    ans.second = max(left.second, right.second) + 1; // height

    return ans;
}

// height is balanced or not for all nodes...
// that is <= 1
// not optimized
bool check_for_balance_tree(Node* root)
{
    if(root == NULL)
        return true;

    bool left = check_for_balance_tree(root->left);
    bool right = check_for_balance_tree(root->right);
    
    bool diff = abs( Height_of_Binary_tree_recursion(root->left) -
                     Height_of_Binary_tree_recursion(root->right) ) <= 1;
    
    if(left && right && diff)
        return true;
    else
        return false; 

}

// optimized
pair<bool, int> check_for_balance_tree_fast(Node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = check_for_balance_tree_fast(root->left);
    pair<bool, int> right = check_for_balance_tree_fast(root->right);
    
    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    
    pair<bool, int> ans;
    
    ans.first = (leftans && rightans && diff) ? true : false ;

    // if(leftans && rightans && diff)
    //     ans.first = true;
    // else
    //     ans.first = false; 

    ans.second = max(left.second , right.second) + 1; 
    
    return ans;
}

bool Determine_trees_identical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        return false;
    
    bool left = Determine_trees_identical(root1->left, root2->left);
    bool right = Determine_trees_identical(root1->right, root2->right);
    bool val = root1->data == root2->data;

    if(left && right && val)
        return true;
    else
        return false;
}


// root/parent is equal to sum of left and right nodes/sub-tree
pair<bool, int>isSumTreePast(Node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftans = isSumTreePast(root->left);
    pair<bool, int> rightans = isSumTreePast(root->right);
    
    bool left = leftans.first;
    bool right = rightans.first;
    bool condition = root->data == leftans.second + rightans.second;

    pair<bool, int> ans;
    
    if(left && right && condition)
    {
        ans.first = true;
        ans.second = root->data + leftans.second + rightans.second;
                    // 2* root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool sum_tree_or_not(Node* root)
{
    return isSumTreePast(root).first;
}

int main()
{
    /*
        cout<<"\n The Height is: "<<Height_of_Binary_tree(root)<<endl;

        cout<<diameter_of_binary_tree(root)<<endl;
        cout<<diameter_optimized(root).first;

        cout<<check_for_balance_tree(root)<<endl;
        cout<<check_for_balance_tree_fast(root).first<<endl;

    */
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //3 1 -1 -1 2 -1 -1

    Node* root = NULL;
    root = built_binary_tree(root);

    sum_tree_or_not(root);

    return 0;
}