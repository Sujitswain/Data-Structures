#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = arr.size();
    int ans = 0;
    deque<int> maxi(k), mini(k);


    // 1 st k-size window
    for(int i=0; i<k; i++)
    {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    
    for(int i=k; i<n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // next window
        while( !maxi.empty() && (i - maxi.front() >= k) )
            maxi.pop_front();

        while( !mini.empty() && (i - mini.front() >= k) )
            mini.pop_front();

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        cout<<ans<<endl;
    }
    ans += arr[maxi.front()] + arr[mini.front()];
    
    cout<<ans;
    return 0;
}