/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

//--------------solved using lcs table refer to lcs and print lcs first. we used lcs table to get common chars and uncommon chars sequenctially so that its subsequence results in string A and B



//function to find lcs 
string f(int n, int m, string &s1, string &s2){
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
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int left = dp[i-1][j];
                    int right = dp[i][j-1];
                    dp[i][j] = max(left, right);
                }
            }
        }

		string ans;

		int i=n, j=m; 
		while(i>0 && j>0){
			if(s1[i-1] == s2[j-1]){
                ans = ans + s1[i-1];
				i--;
                j--;
			}
			else if(dp[i-1][j] >dp[i][j-1]){
                ans = ans + s1[i-1];
				i--;
            }
			else if(dp[i-1][j] < dp[i][j-1]){
                ans = ans + s2[j-1];
				j--;
            }
            else{
                if(i!=0){
                    ans = ans + s2[j-1];
                    j--;
                }
                else if(j!=0){
                    ans = ans + s1[i-1];
                    i--;
                }
            }

		}
        //to use remaining characters
		while(i>0)
            ans = ans + s1[--i];
        while(j>0)
            ans = ans + s2[--j];

		return ans;
}



    string shortestCommonSupersequence(string str1, string str2) {
        string ans = f(str1.length(), str2.length(), str1, str2);
        reverse(ans.begin(), ans.end());
        return ans;
    }