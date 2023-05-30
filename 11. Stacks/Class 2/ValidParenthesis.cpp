#include<iostream>
#include<stack>
using namespace std;

// function to check valid parethesis
//Approach: pushing opening braces to stack. When pushing closing bracket check whether s.top() is the opening bracket for the current closing bracket or not. If it is then pop that opening bracket and if not then push the current closing bracket into the stack.
bool validParenthesis(string &str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char bracket= str[i];
        if(bracket=='(' || bracket== '{' || bracket=='['){
            s.push(bracket);
        }
        else{
            if(s.empty()){
                return false;
            }
            else if(bracket==')' && s.top()=='('){
                s.pop();
            }
            else if(bracket=='}' && s.top()=='{')
                s.pop();
            else if(bracket== ']' && s.top() == '[')
                s.pop();
            else 
                return false;
        }
    }
    if(s.empty()){
        return true;
    }
    else 
        return false;
    
}

int main(){
    string str = "({([(])]))";

    cout<<validParenthesis(str);
}
