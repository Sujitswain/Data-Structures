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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen)
{
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }        
        return;
    }

    sum += root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

// longest height sum
void longest_path_sum(Node* root)
{
    int len = 0, sum = 0;
    int maxLen = 0, maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    cout<<"Maxsum: "<<maxSum<<endl;
}

void k_sum_solution(Node* root, int k, int &count, vector<int> path)
{
    if(root == NULL)
        return;

    path.push_back(root->data);
    k_sum_solution(root->left, k, count, path);
    k_sum_solution(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i-- )
    {
        sum += path[i];
        if(sum == k)
        {
            for(int j=i; j<size; j++)
            {
                cout<<path[j]<<" ";
            }
            cout<<endl;
            count++;
        }
    }
    path.pop_back();
}

// k - sum path
void k_sum(Node* root, int k)
{
    vector<int> path;
    int count = 0;

    k_sum_solution(root, k, count, path);

    cout<<count<<endl;
}

// sum equal to subtree
int count_subtrees_equal_sum(Node* root, int x)
{
    static int count = 0;
    static Node* temp = root;
    int left_Subtree = 0, right_Subtree = 0;

    if(root == NULL)
        return 0;

    left_Subtree += count_subtrees_equal_sum(root->left, x);
    right_Subtree += count_subtrees_equal_sum(root->right, x);
    
    int sum = left_Subtree + right_Subtree + root->data;

    if(sum == x)
        count++;
    
    if(temp != root)
        return left_Subtree + right_Subtree + root->data;

    return count;
}

// least common ancester/parent binary tree
Node* least_common_ancester(Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* leftAns = least_common_ancester(root->left, n1, n2);
    Node* rightAns = least_common_ancester(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
        return root;

    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;

    else
        return NULL;
}

Node* kth_ancester(Node* root, int n1, int &k)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1)
        return root;
    
    Node* leftans = kth_ancester(root->left, n1, k);
    Node* rightans = kth_ancester(root->right, n1, k);

    if(leftans != NULL && rightans == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftans;
    }

    if(leftans == NULL && rightans != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    
    return NULL;
}

void find_kth_ancester(Node* root, int n1, int k)
{
    Node* ans = kth_ancester(root, n1, k);
    if(ans == NULL || ans->data == n1)
        cout<<-1;
    else
        cout<<ans->data;
}

pair<int, int> solve_max_sum_non_adj(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve_max_sum_non_adj(root->left);
    pair<int, int> right = solve_max_sum_non_adj(root->right);

    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    
    return ans;
}

void max_sum_non_adjacent_nodes(Node* root)
{
    pair<int, int> ans = solve_max_sum_non_adj(root);
    cout<<max(ans.first, ans.second);
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
    
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1

    /*
        longest_path_sum(root);

        cout<< least_common_ancester(root, 8, 6)->data; 

        k_sum(root, 7);  

        find_kth_ancester(root, 7, 1);
    */

    Node* root = NULL;
    root = build_binary_tree(root);

    level_order_traversal(root);

    max_sum_non_adjacent_nodes(root);

    return 0;
}