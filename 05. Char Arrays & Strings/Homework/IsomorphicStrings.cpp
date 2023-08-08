/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/


bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, bool> map2;
        
        for(int i=0; i<s.size(); i++){
            if(!map[s[i]]){
                if(map2[t[i]])
                    return false;
                map[s[i]] = t[i];
                map2[t[i]] = true;
            }
            else{
                if(map[s[i]] != t[i])
                    return false;
                if(map2[t[i]] !=s[i])
                    return false;
            }
        } 
        return true;
    }