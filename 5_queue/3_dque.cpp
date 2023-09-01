#include<bits/stdc++.h>
using namespace std;

class Dque
{
    public:
        int *arr;
        int size;
        int qfront;
        int qrear;

        Dque(int size)
        {
            this->size = size;
            arr = new int[size];
            qfront = -1;
            qrear = -1;
        }

        void push_front(int data)
        {
            if(isFull())
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }

            // first or single element
            else if(isEmpty())
                qfront = qrear = 0;

            // cyclic
            else if(qfront == 0 && qrear != size-1)
                qfront = size-1;
            
            // normal flow 
            else
                qfront--;

            arr[qfront] = data;
            cout<<"Value inserted from front: "<<arr[qfront]<<endl;
        }

        void push_rear(int data)
        {
            if(isFull())
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }

            // single or first element
            else if(isEmpty())
                qrear = qfront = 0;

            // cyclic
            else if(qrear == size-1 && qfront != 0)
                qrear = 0;

            // normal
            else
                qrear++;
            
            arr[qrear] = data;
            cout<<"value Inserted from rear: "<<arr[qrear]<<endl;
        }

        void pop_front()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }

            int ans = arr[qfront];
            arr[qfront] = -1;

            // if single elemnt exists
            if(qfront == qrear)
                qfront = qrear = -1;

            // cyclic
            else if(qfront == size -1)
                qfront = 0;

            // normal
            else
                qfront++;

            cout<<"Value Deleted from front: "<<ans<<endl;
        }

        void pop_rear()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }

            int ans = arr[qrear];
            arr[qrear] = -1;

            // if single elemnt exists
            if(qfront == qrear)
                qfront = qrear = -1;

            // cyclic
            else if(qrear == 0)
                qrear = size-1;
            
            // rear
            else
                qrear--;

            cout<<"Value Deleted from front: "<<ans<<endl;
        }

        void getFront()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Front : "<<arr[qfront]<<endl;
        }

        void getRear()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Rear : "<<arr[qrear]<<endl;
        }

        bool isEmpty()
        {
            if(qfront == -1)
                return true;
            
            return false;
        }

        bool isFull()
        {
            if( (qfront == 0 && qrear == size-1)
               || ( qfront != 0 && qrear == ( (qfront-1) % (size-1)) ) )
                return true;

            return false;
        }
};

int main()
{

    return 0;
}