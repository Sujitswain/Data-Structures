#include<bits/stdc++.h>
using namespace std;

class CricularQueue
{
    public:
        int *arr;
        int size;
        int qfront;
        int qrear;

    CricularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    void push(int data)
    {
        if( ( qfront == 0 && qrear == size-1 ) ||
            ( qrear == ( (qfront-1) % (size-1)) ) )
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }

        // single element
        else if(qfront == -1)
            qrear = qfront = 0;

        // cyclic queue
        else if(qrear == size-1 && qfront != 0)
            qrear = 0;

        // normal flow
        else
            qrear++;
        
        arr[qrear] = data;
        cout<<"value inserted: "<<arr[qrear]<<endl;
    }

    void pop()
    {
        if(qfront == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        // if single elemnt exists
        if(qfront == qrear)
            qfront = qrear = -1;

        // all deleted from back, if from left side 
        // some letter exists then point to that
        else if(qfront == size -1)
            qfront = 0;

        // normal flow
        else
            qfront++;

        cout<<"Value Deleted: "<<ans<<endl;
    }

};

int main()
{
    CricularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    // overflow
    q.push(60);

    q.pop();

    q.push(60);

    return 0;
}