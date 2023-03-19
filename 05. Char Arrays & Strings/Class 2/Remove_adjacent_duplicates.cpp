/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/

#include<bits/stdc++.h>
using namespace std;


//Approach: using another string.
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int j= ans.length()-1;                     //variable to keep the pointer on the last element of ans string
        int i=0;                                   //variable to traverse string s

        //loop to push elements from string s to ans only when ans is enpty or last element in ans is not equal to the current element in strin gs
        while(i<s.length()){
            if(ans.length()==0 || ans[j] != s[i]){
                ans.push_back(s[i]);
                i++;
                j++;
            }
            else if(ans[j] == s[i]){
                ans.pop_back();
                i++;
                j--;
            }
            
        }
        return ans;

    }
};