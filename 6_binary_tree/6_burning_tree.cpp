#include<bits/stdc++.h>
using namespace std;

/*
    1. child to parrent node mapping (level order)
    2. find target node
    3. burn minimum time (map for visited or not) 
                         (queue for traversal)
    
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

// does mapping
// returns target node
Node* create_parent_mapping(Node* root, int target, 
                            map<Node* , Node*> &node_to_parent)
{
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);
    node_to_parent[root] = NULL;

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front->data == target)
            res = front;

        if(front->left)
        {
            node_to_parent[front->left] = front;
            q.push(front->left);
        }
        
        if(front->right)
        {
            node_to_parent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burn_Tree(Node* root, map<Node* , Node*> node_to_parent)
{
    map<Node*, bool> visited;
    queue<Node*> q;
    int time = 0;
    
    q.push(root);
    visited[root] = true;


    while(!q.empty())
    {
        bool flag = 0;
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;    
            }
            
            if(front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;    
            }
            
            if(node_to_parent[front] && !visited[node_to_parent[front]])
            {
                flag = 1;
                q.push(node_to_parent[front]);
                visited[node_to_parent[front]] = 1;
            }
        }
        if(flag == 1)
            time++;
    }

    return time;
}

int minTime(Node* root, int target)
{

    map<Node* , Node*> node_to_parent;
    Node* start = create_parent_mapping(root, target, node_to_parent);
    int time = burn_Tree(start, node_to_parent);

    return time;
}

int main()
{
    Node* root = NULL;

    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1

    root = build_binary_tree(root);
    level_order_traversal(root);

    cout<<"Minimum time: "<<minTime(root, 8);

    return 0;
}