/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/


//------------------Solution----------------------



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



    int longestPalindromeSubseq(string s) {
     string s2 = s;
     reverse(s2.begin(), s2.end());
     int n = s.size();
     int m = n;

     //vector<vector<int>> dp(n, vector<int> (m, -1));
     return f(n, m, s, s2);   
    }