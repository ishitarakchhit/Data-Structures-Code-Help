/*
https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/


#include<iostream>
#include<vector>
using namespace std;

bool ischecko(int o, int c, int n){
    if(o> n)
        return false;
    return true;
}
bool ischeckc(int o, int c, int n){
    if(c>o || c>n)
        return false;
    return true;
}

void rec(int o, int c, int n, string ans, vector<string>& output){
    if(o>=n && c>=n){
        cout<<ans<<" ";
        output.push_back(ans);
        return;
    }

    //open
    if(ischecko(o+1, c, n)){
        ans.push_back('(');
        o++;
        rec(o, c, n, ans, output);
        ans.pop_back();
        o--;
        
    }

    //close
    
    if(ischeckc(o, c+1, n)){
        ans.push_back(')');
        c++;
        rec(o, c, n, ans, output);
        
    }
    
}

int main(){
    int n=3;
    vector<string> output;
    string ans="";
    cout<<ans;
    int o =0, c=0;

    rec(o, c, n, ans, output);
    cout<<endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
}