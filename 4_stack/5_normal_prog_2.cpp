#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> arr, int a, int b)
{
    if(arr[a][b] == 1)
        return true;
    else
        return false;
}

void popular_candidate_problem()
{
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = arr.size();

    stack<int> s;
    for(int i=0; i<arr.size(); i++)
        s.push(i);
    
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(arr, a, b))
            s.push(b);
        else
            s.push(a);
    }
    int candidate = s.top();
    
    // he knows none
    int rowCount = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[candidate][i] == 0)
            rowCount++;
    }
    if(rowCount != n)
        return;

    // every one knows him except himself 
    int colCount = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i][candidate] == 1)
            colCount++;
    }
    if(colCount != n-1)
        return;

        cout<<"Popular Candidate: "<<candidate<<endl;
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

int largest_area_histogram_brute_force(vector<int> v)
{   
    cout<<"Matrix: \n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    vector<int> next(v.size());
    next = next_smaller_element(v);
    
    vector<int> prev(v.size());
    prev = prev_smaller_element(v);
    
    int max_area = INT_MIN;

    for(int i=0; i<v.size(); i++)
    {
        int l = v[i];

        if(next[i] == -1)
            next[i] = v.size();
        
        int b = next[i] - prev[i] - 1;
        int area = l*b;
        max_area = max(max_area, area);
    }
    cout<<max_area<<endl<<endl;
    return max_area;
}

void max_rectangle_in_binary_matrix()
{
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    int n = mat.size(), m = mat[0].size();
    int ans = largest_area_histogram_brute_force(mat[0]);
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] != 0)
                mat[i][j] = mat[i][j] + mat[i-1][j];
            else
                mat[i][j] = 0;
        }
        ans = max(ans, largest_area_histogram_brute_force(mat[i]));
    }
    cout<<ans;
}

int main()
{
    /*

    popular_candidate_problem();

    */

    max_rectangle_in_binary_matrix();

    return 0;
}