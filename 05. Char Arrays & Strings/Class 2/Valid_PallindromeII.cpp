/*
[   https://leetcode.com/problems/valid-palindrome-ii/description/  ]
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //function to check if substring is a pallindrome or not 
    bool check(string s, int i, int j){
        string temp;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0, j=s.length()-1;
        int count=0;

        //loop to iterate over the string and
        while(i<j){
            if(s[i]!= s[j]){                                       
                return check(s,i+1, j) || check (s, i, j-1);        //returns true whenever string becomes pallindrome by removing a character
                
            }
            else{
                i++;
                j--;
            }
        }
        
        return 1;

    }
};