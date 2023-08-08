/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

bool isVowel(char ch){
        switch(ch){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': return true;
            default: return false;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0; 
        int j= s.size()-1;
        
        while(i<j){
            if(isVowel(s[i]) == false)
                i++;
            else if(isVowel(s[j]) == false)
                j--;
            else{
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }