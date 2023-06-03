#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    //to push elements in the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(3);
    q.push(3);
    q.push(3);
    q.push(3);
    q.push(3);
    //to pop elements from queue
    q.pop();
    cout<<endl<<q.front();

    cout<<endl<<q.size()<<endl; //to find the size of queue

    //loop to print all elements of the queue
    while(!q.empty()){         //to check if the queue if empty or not
        cout<<q.front()<<" ";
        q.pop();
    }
}