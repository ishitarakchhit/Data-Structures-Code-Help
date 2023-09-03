/*
You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.



A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.



Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.

Output: 3

Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.
Input Format:
The First line of the test case contains the string ‘str1’.

The Second line contains the string ‘str2’.
Output Format:
Return an integer representing the length of the longest common substring.
Note:
You don’t need to print anything. Just implement the given function.
*/



//---------------Solution: direct modification to tabulation-----------------

/*
int f(int n, int m, string &str1, string &str2){
    //we are using shifting of index to reperest base case that has index -1
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        int ans = 0;

        //when n<0 and m>0 they return 0
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
        
        //when m<0 and n>0 they return 0
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
        

}*/


//space opt solution
int f(int n, int m, string &str1, string &str2){
    //we are using shifting of index to reperest base case that has index -1
        vector<int> curr(m+1, -1);
        vector<int> prev(m+1, -1);
        int ans = 0;

        //when n<0 and m>0 they return 0
        for(int j=0; j<=m; j++)
            prev[j] = 0;
        
        //when m<0 and n>0 they return 0
        curr[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){

                    curr[j] = 1 + prev[j-1];
                    ans = max(ans, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        return ans;
        

}

int lcs(string &str1, string &str2){
    int n = str1.length();
    int m = str2.length();

    return f(n, m, str1, str2);

}