#include<bits/stdc++.h>
using namespace std;

class kQueue
{
    private:
        int n;
        int k;
        int freespace;
        int *arr;
        int *front;
        int *rear;
        int *next;
    
    public:
        kQueue(int n, int k)
        {
            this->n = n;
            this->k = k;
            
            arr = new int[n];
            next = new int[n];
            for(int i=0; i<n; i++)
                next[i] = i+1;

            next[n-1] = -1;

            front = new int[k];
            rear = new int[k];
            for(int i=0; i<n; i++)
                front[i] = rear[i] = -1;
            
            freespace = 0;
        }

        void enQueue(int data, int qn)
        {
            if(freespace == -1)
            {
                cout<<"No free space available";
                return;
            }

            // index
            int index = freespace;

            // update
            freespace = next[index];

            // update FRONT
            // check if 1st element
            if(front[qn-1] == -1)
            {
                front[qn-1] = index;
            }
            // if not 1st element then link to prev element
            else
            {
                next[rear[qn-1]] = index;
            }
            
            // update next
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            //push
            arr[index] = data;
        }

        int dQueue(int qn)
        {
            if(front[qn-1] == -1)
            {
                cout<<"Empty"<<endl;
                return -1;
            }
            // find index to pop
            int index = front[qn-1];

            front[qn-1] = next[index];

            next[index] = freespace;

            freespace = index;

            return arr[index];
        }
};

int main()
{
    kQueue q(10, 3);
    q.enQueue(10, 1);
    q.enQueue(15, 1);
    q.enQueue(20, 2);
    q.enQueue(25, 1);

    cout<<q.dQueue(1)<<endl;
    cout<<q.dQueue(2)<<endl;
    cout<<q.dQueue(1)<<endl;
    cout<<q.dQueue(1)<<endl;

    return 0;
}