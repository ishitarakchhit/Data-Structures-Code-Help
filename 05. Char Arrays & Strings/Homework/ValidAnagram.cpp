/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        //to map the frequencies of s string
        for(int i=0; i<s.size(); i++){
            map[s[i]] ++;
        }

        //check if all ch are mapped of string t
        for(int i=0; i<t.size(); i++){
            if(map[t[i]]){
                map[t[i]]--;
            }
            else
                return false;
        }
        
        //if all elements in map have not been visited then return false
        for(auto i:map){
            if(i.second >0)
                return false;
        }
        return true;
    }