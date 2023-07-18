#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creates a max heap
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    cout<<"top element: "<<pq.top()<<endl;
    pq.pop();
    pq.pop();
    cout<<"top element: "<<pq.top()<<endl;
    cout<<"current size: "<<pq.size()<<endl;
    pq.empty()?cout<<"PQ is empty":cout<<"PQ is not empty";

    cout<<"\n\n";
    //creates a min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(100);
    pq2.push(40);
    pq2.push(50);
    pq2.push(79);
    cout<<"top element: "<<pq2.top()<<endl;
    pq2.pop();
    pq2.pop();
    cout<<"top element: "<<pq2.top()<<endl;
    cout<<"current size: "<<pq2.size()<<endl;
    pq2.empty()?cout<<"PQ is empty":cout<<"PQ is not empty";


}