/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/



//-------------Solution---------------------
/*
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //when curr chars are equal=>take the current char of i or ignore it
        int a = 0, b=0;
        if(s[i] == t[j]){
            a = f(s, t, i-1, j-1, dp) + f(s, t, i-1, j, dp);
        }
        else{
            b = f(s, t, i-1, j, dp);
        }
        dp[i][j] = a+b;
        return dp[i][j];

    }
    

    int f(string &s, string &t, int n, int m){
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        
        //base cases
        //1-based indexing
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int j=1; j<=m; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                double a=0, b=0;
                if(s[i-1] == t[j-1]){
                    a = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    b = dp[i-1][j];
                }
                dp[i][j] = a+b;
            }
        }

        return dp[n][m];

    }


    int f(string &s, string &t, int n, int m){
        
        vector<double> curr(m+1, 0);
        vector<double> prev(m+1, 0);
        //base cases
        //1-based indexing
        prev[0] = 1;
        curr[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                double a=0, b=0;
                if(s[i-1] == t[j-1]){
                    a = prev[j-1] + prev[j];
                }
                else{
                    b = prev[j];
                }
                curr[j] = a+b;
            }
            prev = curr;
        }

        return curr[m];

    }
    */

    int f(string &s, string &t, int n, int m){
        vector<double> curr(m+1, 0);
        curr[0] =1;

        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                double a=0, b=0;
                if(s[i-1] == t[j-1]){
                    a = curr[j-1] + curr[j];
                }
                else{
                    b = curr[j];
                }
                curr[j] = a+b;
            }
            
        }

        return curr[m];

    }


    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return f(s, t, n, m);
    }