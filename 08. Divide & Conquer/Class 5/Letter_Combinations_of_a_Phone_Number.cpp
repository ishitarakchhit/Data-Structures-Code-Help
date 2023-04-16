/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/933489423/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

#include<bits/stdc++.h>
using namespace std;

void rec(vector<string>& str, vector<string>& ans, string& output, int index, string& digit){
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int number= digit[index] - '0';
    string value = str[number];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        rec(str, ans, output, index+1, digit);
        //backtracking 
        output.pop_back();
    }
    
}

int main(){
    vector<string> str(10);
    str[2] = "abc";
    str[3] = "def";
    str[4] = "ghi";
    str[5] = "jkl";
    str[6] = "mno";
    str[7] = "pqrs";
    str[8] = "tuv";
    str[9] = "wxyz";

    string digit = "232";
    string output;
    vector<string> ans;

    rec(str, ans, output, 0, digit);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}