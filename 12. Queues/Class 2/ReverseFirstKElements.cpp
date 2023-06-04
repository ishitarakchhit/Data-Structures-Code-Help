#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKElements(queue<int> &q, int k){
    int rev = k;
    if(q.size()<k){
        cout<<"Enter a valid value of K\n";
        return;
    }
    stack<int> s;
    while(k){
        s.push(q.front());
        q.pop();
        --k;
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int size = q.size()-rev;
    while(size){
        int temp = q.front();
        q.pop();
        q.push(temp);
        size--;
    }


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

    reverseKElements(q, -7);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}