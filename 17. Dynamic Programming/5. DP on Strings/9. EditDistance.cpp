/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/




//-----Solution------------

/*
    int f(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(j<0){
            return i+1;
        }

        if(i<0){
            return j+1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            dp[i][j] = 0 + f(word1, word2, i-1, j-1, dp);
            return dp[i][j];
        }

        else{
            int ins = 1 + f(word1, word2, i, j-1, dp);
            int del = 1 + f(word1, word2, i-1, j, dp);
            int rep = 1 + f(word1, word2, i-1, j-1, dp);
            dp[i][j] = min(min(ins, del), rep);
            return dp[i][j];
        }
    }
    

    int f(string &word1, string &word2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j<=m; j++){
            dp[0][j] = j;
        }

        for(int i =1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }

                else{
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int rep = 1 + dp[i-1][j-1];
                    dp[i][j] = min(min(ins, del), rep);
                }
            }
        }
        return dp[n][m];

    }
    */

    int f(string &word1, string &word2, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        if(n == 0 && m ==0) return 0;
        curr[0] = 1;

        for(int j = 0; j<=m; j++){
            prev[j] = j;
        }

        for(int i =1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = 0 + prev[j-1];
                }

                else{
                    int ins = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];
                    curr[j] = min(min(ins, del), rep);
                }
            }
            prev = curr;
            curr[0] = i+1;                                 //mistake------
        }
        return prev[m];

    }

    

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        return f(word1, word2, n, m);
    }