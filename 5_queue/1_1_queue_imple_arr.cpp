#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public: 
        int *arr;
        int size;
        int qfront;
        int qrear;

        Queue(int size)
        {
            this->size = size;
            arr = new int[size];
            qfront = 0;
            qrear = 0;
        }

        void push(int data)
        {
            if(qrear == size)
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }
            else
            {
                arr[qrear] = data;
                cout<<"value inserted: "<<arr[qrear]<<endl;
                qrear++;
            }
        }
        
        void pop()
        {
            if(qfront == qrear)
            {
                cout<<"Queue Underflow"<<endl;
                return;
            }
            else
            {
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;

                if(qrear == qfront)
                {
                    qrear = 0;
                    qfront = 0;
                }
                cout<<"value removed: "<<ans<<endl;
            }
        }

        void isEmpty()
        {
            if(qfront == qrear)
            {
                cout<<"Empty"<<endl;
                return;
            }
            else
            {
                cout<<"Not Empty"<<endl;
                return;
            }
        }

        void front()
        {
            if(qfront == qrear)
            {
                cout<<"Empty"<<endl;
                return;
            }

            cout<<"Front value: "<<arr[qfront]<<endl;
        }

};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);    

    q.front();
    q.isEmpty();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.isEmpty();
    q.pop();
    q.isEmpty();
    

    return 0;
}