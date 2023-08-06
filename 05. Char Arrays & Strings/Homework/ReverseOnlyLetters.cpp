/*
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/

//Approach: two pointer
#include<iostream>
using namespace std;
bool isalphabet(char ch){
        int num = ch-'a';
        if(num<26 && num>=0)
            return true;
        num = ch-'A';
        if(num<26&& num>=0)
            return true;
        return false;
    }
    string reverseOnlyLetters(string &s) {
        int i=0; 
        int j= s.length()-1;

        while(i<j){
            char ch = s[i];
            if(isalphabet(ch) == false){
                i++;
            }
            else if(isalphabet(s[j]) == false){
                j--;
            }
            else{
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

    int main(){
        string str = "ab-cd";
        cout<<reverseOnlyLetters(str);
    }