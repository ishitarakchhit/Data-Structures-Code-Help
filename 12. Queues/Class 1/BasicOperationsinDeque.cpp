#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(10);
    d.push_front(100);
    d.pop_front();
    d.pop_back();
    d.size();

    if(d.empty())  cout<<"deque is empty";
    else cout<<"not empty";

    return 0;
}