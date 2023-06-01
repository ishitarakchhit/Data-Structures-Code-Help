/*
Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

For Example :
((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
While (a + (b*c)) does not have any pair of redundant brackets. 
*/

#include<iostream>
#include<stack>
using namespace std;

// function to check if the expression containts redundant brackets or not
//Approach: pushing opening braces to stack. When pushing closing bracket check whether s.top() is the opening bracket for the current closing bracket or not. If it is then pop that opening bracket and if not then push the current closing bracket into the stack.

bool solve(string &str, stack<char> &s, int &i){
    if(i == str.length()){
        return false;
    }

    char curr = str[i];
    
    if(curr == '(' || curr == '*' || curr == '+' || curr == '-' || curr == '/'){
        s.push(curr);
        i++;
    }
    else if(curr == ')'){
        if(s.top() == '('){
            return true;
        }
        else{
            while(s.top() != '('){
                s.pop();
            }
            s.pop();
            i++;
        }
    }
    else{
        i++;
    }


    solve(str, s, i);
}

bool redundantBrackets(string &str){
    if(str.length()==0){
        return true;
    }
    
    stack<char> s;
    int i=0;
    
    
    return solve(str, s, i);
    
}

int main(){
    string str = "((a*b)*c)";

    if(redundantBrackets(str)){
        cout<<str<<" has redundant brackets";
    }
    else{
        cout<<str<<" has no redundant brackets";
    }

    return 0;
}
