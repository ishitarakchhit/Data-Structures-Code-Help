#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    //to insert element to a stack
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    //to peek at the top element
    cout<<s.top();

    //to remove the top element
    s.pop();

    //to check whether stack is empty or not
    cout<<s.empty();

    //to find the size of stack
    cout<<s.size();

    //to print all elements(this also removes all elements)
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
    
    
    return 0;


}