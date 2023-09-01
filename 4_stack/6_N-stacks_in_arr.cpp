#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
        int *arr;
        int *top;
        int *next;

        // n : number of stacks
        // s : size of arr
        int n, s;
        int freespot;

    Stack(int n, int s)
    {
        this->n = n;
        this->s = s;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        // initialize all array element to -1;
        // memset use 0, -1 for integral values
        for(int i=0; i<n; i++)
            top[i] = -1;

        for(int i=0; i<s; i++)
            next[i] = i+1;
        
        // update last index 
        next[s-1] = -1;

        freespot = 0;        
    }

    void push(int x, int m)
    {
        if(freespot == -1)
        {
            cout<<"array full"<<endl;
            return;
        }
        int index = freespot;

        freespot = next[index];

        arr[index] = x;
        
        next[index] = top[m-1];

        top[m-1] = index;

        return;
    }

    int pop(int m)
    {
        if(top[m-1] == -1)
            return -1;

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;
        
        freespot = index;

        return arr[index];
    }

};

int main()
{
    Stack s(2, 5);



    cout<<"freesopt: "<<s.freespot<<endl;

    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;

    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;




    s.push(10,1);
    cout<<"freesopt: "<<s.freespot<<endl;

    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;

    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;
    


    s.push(20,1);
    cout<<"freesopt: ";
    cout<<s.freespot<<endl;
    
    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;
    
    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;




    s.push(30,1);
    cout<<"freesopt: ";
    cout<<s.freespot<<endl;
    
    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;
    
    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;
    



    s.push(40,2);
    cout<<"freesopt: ";
    cout<<s.freespot<<endl;
    
    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;
    
    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;
    
    


    s.push(50,2);
    cout<<"freesopt: ";
    cout<<s.freespot<<endl;
    
    cout<<"top_arr: ";
    for(int i=0; i<s.n; i++)
        cout<<s.top[i]<<" ";
    cout<<endl;
    
    cout<<"next_arr: ";
    for(int i=0; i<s.s; i++)
        cout<<s.next[i]<<" ";
    cout<<endl<<endl;

    return 0;
}