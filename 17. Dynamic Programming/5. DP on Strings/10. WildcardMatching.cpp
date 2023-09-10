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



//-------------Solution------------------

/*
    bool f(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(j<0){
            return i<0;
        }
        if(i<0){
            //if the remaining chs in pattern string are * then return true else false
            for(int jj=0; jj<=j; jj++){
                if(p[jj] != '*') return false;
            }
            return true;
        }
            
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            dp[i][j] = f(s, p, i-1, j-1, dp);
            return dp[i][j];
        }
        else if(p[j] == '*'){
            dp[i][j] = f(s, p, i-1, j, dp)  || f(s, p, i, j-1, dp);
            return dp[i][j];
        }
        else{                    //when both are not equal
            dp[i][j] = false;
            return dp[i][j];
        }
        
    }

    bool f(string &s, string &p, int n, int m){
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        
        //base cases
        //1-based indexing
        //when both strings are exhausted
        dp[0][0] = 1;

        //when pattern string is exhausted then all should be false
        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
        }

        //when main string is exhausted then all characters upto * from starting returns true else false
        int astrick = true;
        for(int j=1; j<=m; j++){
            if(astrick == true){
                if(p[j-1] == '*')
                    dp[0][j] = true;
                else{
                    dp[0][j] = false;
                    astrick = false;
                }
            }
            else{
                dp[0][j] = false;
            }
        }


        for(int i = 1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{                    //when both are not equal
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
    */

    bool f(string &s, string &p, int n, int m){
        vector<bool> prev(m+1, 0);
        vector<bool> curr(m+1, 0);
        
        //base cases
        //1-based indexing
        //when both strings are exhausted
        prev[0] = 1;

        //when pattern string is exhausted then all should be false
        curr[0] = 0;

        //when main string is exhausted then all characters upto * from starting returns true else false
        int astrick = true;
        for(int j=1; j<=m; j++){
            if(astrick == true){
                if(p[j-1] == '*')
                    prev[j] = true;
                else{
                    prev[j] = false;
                    astrick = false;
                }
            }
            else{
                prev[j] = false;
            }
        }
        for(auto i:prev){
            cout<<i<<" ";
        }


        for(int i = 1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }

                else if(p[j-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else{                    //when both are not equal
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return f(s, p, n, m);
    }


