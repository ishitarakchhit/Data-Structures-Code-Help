#include<iostream>
#include<queue>
using namespace std;


queue<int> interleaveQueue(queue<int> q){
    
    
    queue<int> q1;
    int size = q.size()/2; 

    while(size !=0){
        q1.push(q.front());
        q.pop();
        size--;
    }
    size = q.size()/2;
    
    while(q1.empty()==0){
        q.push(q1.front());
        q.push(q.front());
        q1.pop();
        q.pop();
        size--;
    }

    if(size){
        q.push(q.front());
        q.pop();
    }

    return q;
}


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    queue<int> q1=interleaveQueue(q);

    cout<<"Initial queue is: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl<<"Final queue is: ";
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }

    return 0;
}