#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    stack<char> s;
    string str = "Ishita Rakchhit";

    //loop to push all characters to stack s
    for (int i = 0; i < str.length(); i++){
        s.push(str[i]);
    }

    //loop to print all characters from stack s
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    
}