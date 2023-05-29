#include<iostream>
#include<stack>
using namespace std;

//function to push value at bottom of stack using recursion
void pushatbottom(stack<int> &s, int &value, int &i){
    if(s.size() == i){
        s.push(value);
        return;
    }

    int temp = s.top();
    s.pop();
    pushatbottom(s, value, i);
    s.push(temp);
    return;
}

void insertatbottom(stack<int> &s, int &count , int size, int &i){
    
    if(count>= size-1){
        return;
    }
    int value = s.top();
    s.pop();
    i++;
    pushatbottom(s, value, i);
    count++;
    insertatbottom(s, count, size, i);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int count =0;
    int size = s.size();
    int i=-1;
    insertatbottom(s, count, size, i);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}