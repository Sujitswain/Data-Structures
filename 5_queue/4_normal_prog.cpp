#include<bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverse_queue()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // display
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

void recursion_reverse(queue<int> &q)
{
    if(q.empty())
        return;

    int num = q.front();
    q.pop();

    recursion_reverse(q);
    q.push(num);
}

void first_negative_index()
{
    vector<int> v {-8, 2, 3, -6, 10};
    int k = 2;
    deque<int> d;
    vector<int> ans;

    // for 1 st k windows
    for(int i=0; i<k; i++)
    {    
        if(v[i] < 0)
            d.push_back(i);
    }
    if(d.size() > 0)
        ans.push_back(v[d.front()]);
    else
        ans.push_back(0);
        
    // for remaining windows
    for(int i=k; i<v.size(); i++)
    {
        if( (!d.empty()) && (i-d.front() >= k) )
        {
            d.pop_front();
        }
        if(v[i] < 0)
            d.push_back(i);

        if(d.size() > 0)
            ans.push_back(v[d.front()]);
        else
            ans.push_back(0);
    }
    cout<<"Answers: "<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void reverse_first_k_element_of_queue()
{
    queue<int> q;
    int k = 2;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    stack<int> s;
    // first k
    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    for(int i=0; i<k; i++)
    {
        q.push(s.top());
        s.pop();
    }

    int l = q.size() - k;
    while(l--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    display(q);
}

void first_non_repeating_character_in_string()
{
    string s = "aabbc";

    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        count[ch]++;
        q.push(ch);

        while(!q.empty())
        {
            if(count[q.front()] > 1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
            ans.push_back('#');
    }
    cout<<ans<<endl;
}

void circular_tour()
{
    // vector<int> petrol =   {4, 6, 7, 4},
    //             distance = {6, 5, 3, 5};

    vector<int> petrol =   {6, 7, 4, 10, 6, 5},
                distance = {5, 6, 7,  8, 6, 4};

    int start = 0, front = 0, rear = 0, 
        deficit = 0, balance = 0, n = petrol.size();
    
    for(int i=0; i<n; i++)
    {
        balance += petrol[i] - distance[i];
        if(balance < 0)
        {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0)
        cout<<"Start : "<<start<<endl;
    else
        cout<<"Not Possible";

}

void interleave_first_half_queue_second_half()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);

    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    stack<int> s;
    int mid = q.size()/2;
    for(int i=0; i<mid; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<mid; i++)
    {
        q.push(s.top());
        s.pop();
    }

    for(int i=0; i<mid; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for(int i=0; i<mid; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    for(int i=0; i<mid; i++)
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    
    display(q);
}


int main()
{

    /*
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);

        recursion_reverse(q);
        display(q);

        first_negative_index();

        reverse_first_k_element_of_queue();

        first_non_repeating_character_in_string();

        circular_tour();


    */

    interleave_first_half_queue_second_half();

    return 0;
}