/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/


bool solution(string s, string p, int is, int ip){
        if( ip == p.length()){
            if(is != s.length()){
                return false;
            }
            return true;
        }

        if(is == s.length()){
            if(ip == p.length())
                return true;
            else{
                for(; ip<p.length(); ip++){
                    if(p[ip] != '*')
                        return false;
                }
                return true;
            }
            return false;
        }

        if(s[is] == p[ip] || p[ip]=='?'){
            return solution(s, p, is+1, ip+1);
        }
        
        else if(s[is]!=p[ip] && p[ip]!='*')
            return false;
        
        else{
            int ans1 = solution(s, p, is, ip+1);
            int ans2 = solution(s,p, is+1, ip);
            return ans1 || ans2;
        }
        return true;

    }
    bool isMatch(string s, string p) {
        int i=0;
        return solution(s, p, i, 0);
    }