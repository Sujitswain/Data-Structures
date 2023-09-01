#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s)
{
    while( !s.empty() )
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void str_rev()
{
    string str = "reverse";
    stack<char> s;
    
    for(int i=0; i<str.length();i ++)
        s.push(str[i]);

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

// delete_mid(s, 0, s.size());
void delete_mid(stack<int> s, int c, int n)
{
    if(c == n/2)
    {
        cout << s.top() << endl;
        
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    delete_mid(s, c+1, n);
    
    s.push(num);
}

bool valid_parentheses()
{
    string str = "[[[[[[]{}";
    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        else
        {
            if(!s.empty())
            {
                char top = s.top();
                if( 
                    (ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[') 
                  )
                    s.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

void put_bottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();
    put_bottom(s, x);
    s.push(num);
}

void stack_reverse(stack<int> &s)
{
    if(s.empty())
        return;

    int num = s.top();
    s.pop();
    // recursive call
    stack_reverse(s);

    // insert at bottom
    put_bottom(s, num);
}

void sorted_Insert(stack<int> &s, int x)
{
    if( s.empty() || (!s.empty() && s.top() < x) )
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    sorted_Insert(s, x);
    s.push(num);
}

void sort_stack(stack<int> &s)
{
    if(s.empty())
        return;

    int num = s.top();
    s.pop();

    sort_stack(s);

    sorted_Insert(s, num);
}

void Redundant_brackets()
{
    string str = "(a + b)";
    stack<char> s;

    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);
        else
        {
            if(ch == ')')
            {
                bool check = true;
                while(s.top() != '(')
                {
                    char top = s.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                        check = false;

                    s.pop();
                }
                if(check)
                {
                    cout<<"Redundant_brackets found";
                    return;
                }
                s.pop();
            }
        }
    }    
    cout<<"No redundant brackets found";
}

int minimum_cost_to_make_string_valid()
{
    string str = "{{{{{}";
    if((str.length() & 1))
        return -1;

    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        if(ch == '{')
            s.push(ch);
        else
        {
            if(!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
        }
    }

    int a = 0, b = 0;
    while(!s.empty())
    {
        if(s.top() == '{')
            b++;
        else
            a++;
        
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

void longest_valid_parentheses()
{
    string str = "((()";
            //-1  01
            // t = 3 - 2  
    stack<int> s;
    s.push(-1);

    int t = 0, ans = 0;
    
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        if(ch == '(')
            s.push(t);
        else
        {
            if(!s.empty() && (s.top() != -1) && str[s.top()] == '(' )
            {
                s.pop();
                ans = max(ans, abs(t - s.top()));   
            }
            else
                s.push(t);
        }
        t++;
    }
    cout<<"length of parentheses : "<<ans;
}

void next_smaller_element_undestand()
{
    vector<int> v = {2, 1, 4, 3};
    vector<int> ans(v.size());
    
    stack<int> s;
    s.push(-1);

    for(int i=v.size()-1; i>=0; i--)
    {
        int curr = v[i];

        // if top is > element then pop
        while(s.top() >= curr)
            s.pop();

        // stack top is the smaller element
        ans[i] = s.top();
        s.push(curr);
    }

    cout<<endl<<"Next: "<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

vector<int> next_smaller_element(vector<int> v)
{
    vector<int> ans(v.size());
    stack<int> s;
    s.push(-1);

    for(int i=v.size()-1; i>=0; i--)
    {
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr)
            s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    cout<<endl<<"Next: "<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return ans;
}

vector<int> prev_smaller_element(vector<int> v)
{
    vector<int> ans(v.size());
    stack<int> s;
    s.push(-1);

    for(int i=0; i<v.size(); i++)
    {
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr)
            s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    cout<<endl<<"Prev: "<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return ans;
}

void largest_area_histogram_brute_force()
{
    vector<int> v = {2, 3, 3, 2};
    
    vector<int> next(v.size());
    next = next_smaller_element(v);
    
    vector<int> prev(v.size());
    prev = prev_smaller_element(v);
    
    int max_area = INT_MIN;

    for(int i=0; i<v.size(); i++)
    {
        int l = v[i];

        if(next[i] == -1)
        {
            next[i] = v.size();
        }
        int b = next[i] - prev[i] - 1;
        int area = l*b;
        max_area = max(max_area, area);
    }
    cout<<max_area<<endl;
}

int main()
{
    /*
    str_rev();

    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    delete_mid(s, 0, s.size());

    cout << valid_parentheses();

    stack<int> s2;
    s2.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);
    s2.push(9);

    int x = 10;
    put_bottom(s2, x);

    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    display(s);
    stack_reverse(s);
    display(s);

    stack<int> s;
    s.push(11);
    s.push(18);
    s.push(17);
    s.push(12);

    display(s);
    sort_stack(s);
    display(s);

    Redundant_brackets();

    longest_valid_parentheses();

    cout << minimum_cost_to_make_string_valid();

    next_smaller_element();
    
    largest_area_histogram_brute_force();
    */
    
    largest_area_histogram_brute_force();
    
    return 0;
}