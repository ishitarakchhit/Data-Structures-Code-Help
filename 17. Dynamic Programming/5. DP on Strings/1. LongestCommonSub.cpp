/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/


//------------------------Solution-----------------------------

/*
    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        //if current characters are same so they have to be added up to the common subsequence
        if(text1[i] == text2[j])
            return 1 + f(i-1, j-1, text1, text2, dp);
        
        //else if not same check for two cases eg. ac/ce for a/ce and ac/c
        int left = f(i-1, j, text1, text2, dp);
        int right = f(i, j-1, text1, text2, dp);
        dp[i][j] = max(left, right);
        return dp[i][j];
    }

    int f(int n, int m, string text1, string text2){
        //we are using shifting of index to reperest base case that has index -1
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        //when n<0 and m>0 they return 0
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
        
        //when m<0 and n>0 they return 0
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int left = dp[i-1][j];
                    int right = dp[i][j-1];
                    dp[i][j] = max(left, right);
                }
            }
        }

        return dp[n][m];
        
    }*/


    int f(int n, int m, string text1, string text2){
        //we are using shifting of index to reperest base case that has index -1
        vector<int> prev(m+1, -1);
        vector<int> curr(m+1, -1);

        //when n<0 and m>0 they return 0
        for(int j=0; j<=m; j++)
            prev[j] = 0;
        
        //when m<0 and n>0 they return 0
        curr[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else{
                    int left = prev[j];
                    int right = curr[j-1];
                    curr[j] = max(left, right);
                }
            }
            prev = curr;
        }

        return prev[m];
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //ector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n, m, text1, text2);
    }