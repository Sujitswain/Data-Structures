#include<bits/stdc++.h>
using namespace std;

class Stack
{
    private:
        queue<int> q1, q2;

    public:
        void push(int data)
        {                               // 1st element          // 2nd element    
            q2.push(data);              // q2 = 1, q1 = {}      // q2 = 2, q1 = 1
            while(!q1.empty())          // not going            // going
            {                                                   
                q2.push(q1.front());                            // q2 = 2, 1
                q1.pop();                                       // q1 {}
            }                                                   
            queue<int> temp = q1;       // temp{}, q1{}         // temp = q1 = {}
            q1 = q2;                    // q1 = q2 = 1          // q1 = q2 = 2,1
            q2 = temp;                  // q2 = {}              // q2 = {}
        }

        void pop()
        {
            if(q1.empty())
            {
                cout<<"Stack Empty"<<endl;
                return;
            }
            q1.pop();
        }

        void top()
        {
            if(q1.empty())
            {
                cout<<"Stack Empty"<<endl;
                return;
            }
            cout<<"Top: "<<q1.front()<<endl;  
        }
};

int main()
{

    return 0;
}