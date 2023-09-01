#include<bits/stdc++.h>
using namespace std;

void display(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void get_minimun(stack<int> s1, stack<int> &s2)
{
    if(s1.size() == 1)
        s2.push(s1.top());
    else
        s2.push( min(s1.top(), s2.top()) );
}

void recursion(stack<int> s1, stack<int> &s2)
{
    if(s1.empty())
        return;
    
    int num = s1.top();
    s1.pop();
    recursion(s1, s2);
    s1.push(num);
    get_minimun(s1, s2);
}

int help(stack<int> s1)
{
    stack<int> s2;
    recursion(s1, s2);
    return s2.top();
}

class SpecialStack
{
    public:
        stack<int> s;
        int mini;

        void push(int data)
        {
            if(s.empty())
            {
                s.push(data);
                mini = data;
            }
            else
            {
                if(data < mini)
                    s.push(2*data - mini);
                else
                    s.push(data);
            }
        }

        int pop()
        {
            if(s.empty())
                return -1;
            else
            {
                int curr = s.top();
                s.pop();
                
                if(curr > mini)
                    return curr;
                else
                {
                    int prevMini = mini;
                    int val = 2*mini - curr;
                    mini = val;
                    return prevMini;
                }
            }
        }

        int top()
        {
            if(s.empty())
                return -1;

            int curr = s.top();
            if(curr < mini)
                return mini;
            else
                return curr;
        }

        bool isEmpty()
        {
            return s.empty();
        }

        int getMini()
        {
            if(s.empty())
                return -1;

            return mini;
        }
};

int main()
{
    /*
    
    stack<int> s1;
    s1.push(5);   
    s1.push(3);
    s1.push(8);
    s1.push(2);
    s1.push(4);

    cout<<"In stack: "<<endl;
    display(s1);

    cout<<help(s1)<<endl;
    s1.pop();
    cout<<help(s1)<<endl;
    
    s1.pop();
    cout<<help(s1)<<endl;
    
    s1.pop();
    cout<<help(s1)<<endl;
    
    s1.pop();
    cout<<help(s1)<<endl;

    */

    return 0;
}