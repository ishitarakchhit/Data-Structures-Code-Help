/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
 
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

class Solution {
    private:
    bool isvalid(char ch){
    if((ch>='a'&& ch<='z') || (ch>='0' && ch<='9'))
        return 1;
    else 
        return 0;
}

string tolowercase(string s){
    
    for(int i=0; i<s.length(); i++)
        if(s[i]>='A' && s[i]<='Z'){
            s[i]= s[i] +32;
        }
    
    return s;
}
public:
    bool isPalindrome(string s) {
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
        
    }
};




// You can also create another string after removing all the special characters and converting all upper case characters to lower case and then check whether it is a palindrome or not
class Solution {
private:
    bool valid(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return 1;
        }
        
        return 0;
    }
    
    char toLowerCase(char ch) {
    if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
    bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
public:
    bool isPalindrome(string s) {
        
        //faltu character hatado
        string temp = "";
        
        for(int j=0; j<s.length(); j++) {   
            if(valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        
        //lowercase me kardo
        for(int j=0; j<temp.length(); j++) { 
            temp[j] = toLowerCase(temp[j]);
        }
        
        //check palindrome
        return checkPalindrome(temp);
        
    }
};