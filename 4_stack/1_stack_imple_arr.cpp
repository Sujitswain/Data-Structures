#include<bits/stdc++.h>
using namespace std;

/*
        STL

    stack<int> s;
    push, pop, top, empty

    stack<int> s;
    s.push(1);
    s.push(2);

    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty();
*/

class Stack
{
    public:
        int *arr;
        int top;
        int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if(size - top > 1)  
        {
            top++;
            arr[top] = data;
        }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void pop()
    {
        if(top >= 0)
            top--;
        else
            cout<<"Stack Underflow"<<endl;
    }

    int peek()
    {
        if(top >= 0)
            return arr[top];
        else
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

};

int main()
{
    Stack s(5);

    s.push(22);
    s.push(43);
    s.push(44);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    s.pop();
    cout<<s.peek()<<endl;
    
    s.pop();
    cout<<s.peek()<<endl;

    cout<<s.isEmpty();

    return 0;
}