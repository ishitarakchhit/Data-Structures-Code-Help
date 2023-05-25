#include<iostream>
#include<stack>
using namespace std;

void rec(stack<int> &s, int &size, int &ans){
    if(s.size() ==0){
        cout<<"There's no element in stack";
        return;
    }

    if(s.size() == size/2+1){
        ans= s.top();
        return;
    }

    int temp = s.top();
    s.pop();
    
    //recursive call
    rec(s, size, ans);
    
    //backtracking
    s.push(temp);
}

int main(){
    stack<int> s;
    int size = 7;
    int ans =0;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    rec(s, size, ans);
    cout<<ans;
}