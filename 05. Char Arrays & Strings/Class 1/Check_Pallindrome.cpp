/*
You are given a string s and you need to find our whether the given string is a valid palindrome or not ignoring all the special characters or whitespaces and taking in account only digits and alphabets. Treat uppercase and lowercase alphabets as equal
*/

#include <bits/stdc++.h> 

// function to check whether the given character is valid or not
bool isvalid(char ch){
    if((ch>='a'&& ch<='z') || (ch>='0' && ch<='9'))
        return 1;
    else 
        return 0;
}

// function to convert all the uppercase alphabets to lowercase 
string tolowercase(string s){
    
    for(int i=0; i<s.length(); i++)
        if(s[i]>='A' && s[i]<='Z'){
            s[i]= s[i] +32;
        }
    return s;
}

//function to check for a valid palindrome
//Approach: two pointer method
bool checkPalindrome(string s)
{
    s= tolowercase(s);                           
  
    int i=0; 
    int j= s.length()-1;
    while(i<=j){
        if(isvalid(s[i])== 0){
            i++;
        }
        if(isvalid(s[j])== 0)
            j--;
        else if(isvalid(s[j])== 1 && isvalid(s[i])== 1 ){
            if(s[i]== s[j]){
                i++;
                j--;
            }
                
            else{
                return 0;
            }
        }
    }
    return 1;
    
    // Write your code here.
}