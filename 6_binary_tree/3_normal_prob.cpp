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

vector<int> zig_zag_traversal(Node* root)
{
    cout<<"\n Print Zig-Zag :\n ";
    
    // for string answers
    vector<int> ans;

    // if root is null the nothing to do
    if(root == NULL)
        return ans;
    
    // in order to prcess level wise traversal
    queue<Node* >q;
    q.push(root);

    // either left wise or right wise
    bool left_to_right = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);

        // process level
        for(int i=0; i<size; i++)
        {
            Node* frontNode = q.front();
            q.pop();

            int index = left_to_right ? i : size-i-1;
            
            // push the data
            temp[index] = frontNode->data;
            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }

        // direction change
        left_to_right = !left_to_right;
        for(auto i:temp)
            ans.push_back(i);
    }    
    return ans;
}

// left-side except leaf nodes
void traverse_left(Node* root, vector<int> &ans)
{
    // if empty or leaf node
    if(root == NULL || root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);
    if(root->left)
        traverse_left(root->left, ans);
    else
        traverse_left(root->right, ans);
}

// all leaf nodes (both right / left)
void traverse_leaf(Node* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverse_leaf(root->left, ans);
    traverse_leaf(root->right, ans);
}

// right - side except leaf nodes (reversal direction)
void traverse_right(Node* root, vector<int> &ans)
{
    // if empty or leaf nodes
    if(root == NULL || root->left == NULL && root->right == NULL)
        return;

    if(root->right)
        traverse_right(root->right, ans);
    else
        traverse_right(root->left, ans);

    // we need the right data in reverse order
    ans.push_back(root->data);
}

vector<int> boundary_traversal(Node* root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    // for root node
    ans.push_back(root->data);

    // for left part
    traverse_left(root->left, ans);
    
    // for left-side subtree
    traverse_leaf(root->left, ans);
    
    // for right-side subtree
    traverse_leaf(root->right, ans);

    // for right part
    traverse_right(root->right, ans);

    return ans;
}

//vertical traversal
// horizontal distance from root
// -2   -1    0     1      2
//
// 1
// map sorts hd that is key dy default
//
//      hd        lvl      list
// map< int, map<int, vector<int>> >
//
// 2
// in order to traverse in level order
// and provide info about  
// horizontal distance & level we need a queue
//                         hd   lvl
// queue< pair<Node*, pair<int, int> > >
vector<int> vertical_traversal(Node* root)
{
    //    hd       lvl    data-list
    map< int, map< int, vector<int> > > nodes;
    
    //            node       hd  lvl
    queue< pair< Node* ,pair<int, int> > > q;
    
    // storing answer
    vector<int> ans;

    if(root == NULL)
        return ans;
    
    //               node           hd, lvl
    q.push(make_pair(root, make_pair(0, 0)));
    
    while(!q.empty())
    {
        pair<Node* ,pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    for(auto i: nodes)
    {                           // i -> <int, map<int, vector<>>>
        for(auto j : i.second)
        {                       // j -> <int, vector<>>
            for(auto k : j.second)
            {                   // k -> vector<>
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// top view of binary tree
// 1 to 1 mapping because it will 
// hide the nodes coming under it
//     hd   node->data
// map<int, int>
vector<int> top_view_binary_tree(Node* root)
{
    // storing ans
    vector<int> ans;

    // if empty
    if(root == NULL)
        return ans;

    //  hd  node-data-list
    map<int, int> top_view;

    //         node    hd
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // mapping 1 to 1
        // find if not present enter
        if(top_view.find(hd) == top_view.end())
            top_view[hd] = frontNode->data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    for(auto i:top_view)        //   hd  node
    {                           // <int, int>
        ans.push_back(i.second);
    }
}

// bottom view of a binary tree
vector<int> bottom_view_binary_tree(Node* root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> top_view;
        //      node    hd
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        top_view[hd] = frontNode->data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    for(auto i:top_view)        //   hd  node
    {                           // <int, int>
        ans.push_back(i.second);
    }
}

// left view of a binary tree
// just print the first element of all level
// recursion is efficient
// track the level bu using a lvl variable just
// increment 1 by going downward
// if lvl == v.size u get a new level
void solve_left(Node* root, vector<int> &ans, int level)
{
    if(root == NULL)
        return;

    // new level
    if(level == ans.size())
        ans.push_back(root->data);

    solve_left(root->left, ans, level+1);
    solve_left(root->right, ans, level+1);
}

vector<int> left_view_of_a_binary_tree(Node* root)
{
    vector<int> ans;
    solve_left(root, ans, 0);
    return ans;
}

// right view of a binary tree
// just print the first element of all level
// recursion is efficient
// track the level bu using a lvl variable just
// increment 1 by going downward
// if lvl == v.size u get a new level
void solve_right(Node* root, vector<int> &ans, int level)
{
    if(root == NULL)
        return;
    // new level
    if(level == ans.size())
        ans.push_back(root->data);

    solve_right(root->right, ans, level+1);
    solve_right(root->left, ans, level+1);
}

vector<int> right_view_of_a_binary_tree(Node* root)
{
    vector<int> ans;
    solve_right(root, ans, 0);
    return ans;
}

// diagonal view of binary tree
void diagonal_view_of_binary_tree(Node* root, int d, map<int, vector<int>>&ans)
{
    if(root == NULL)
        return;

    ans[d].push_back(root->data);
    diagonal_view_of_binary_tree(root->left, d+1, ans);
    diagonal_view_of_binary_tree(root->right, d, ans);    
}

void diagonal_traversal_binary_tree(Node* root)
{
    map<int, vector<int>> ans;

    diagonal_view_of_binary_tree(root, 0, ans);

    cout<<"Diagonal Traversal: \n";
    for(auto i:ans)
    {
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1

    // 8 3 1 -1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1

    /*
        level_order_traversal(root);
        vector<int> v = zig_zag_traversal(root);
        for(auto i:v)
            cout<<i<<" ";

        vector<int> v = boundary_traversal(root);
        for(auto i:v)
            cout<<i<<" ";
    */

    Node* root = NULL;
    root = built_binary_tree(root);
    // vector<int> v = vertical_traversal(root);
    // for(auto i:v)
    //     cout<<i<<" ";
    
    diagonal_traversal_binary_tree(root);

    return 0;
}