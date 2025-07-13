#include <bits/stdc++.h>
#include "stack.h"

using namespace std;

class MyQueue
{
    int size;
    ArrayStack st1;
    ListStack st2;

public:
    MyQueue()
    {
        size = 0;
    }
    void enqueue(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.pop());
        }
        st1.push(x);
        while (!st2.empty())
        {
            st1.push(st2.pop());
        }
        size++;
    }
    int dequeue()
    {
        size--;
        return st1.pop();
    }
    int Size()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
    int front()
    {
        return st1.top();
    }
    int back()
    {
        while (!st1.empty())
        {
            st2.push(st1.pop());
        }
        int temp = st2.top();
        while (!st2.empty())
        {
            st1.push(st2.pop());
        }
        return temp;
    }
    void display(){
        int temp ;
        while (!st1.empty())
        {   
            temp = st1.pop();
            st2.push(temp );
            cout <<temp <<" ";
        }
        while (!st2.empty())
        {
            st1.push(st2.pop());
        }
        cout << endl ;
        

    }
};

int main(){
    MyQueue q ;
    for(  int i = 0 ; i < 6 ; i++){
        q.enqueue(2*i);
    }
    q.display();
    cout << "Dequeued: "<<q.dequeue()<<endl ;
    q.display();
    cout <<"SIze:" <<q.Size()<<endl;

}