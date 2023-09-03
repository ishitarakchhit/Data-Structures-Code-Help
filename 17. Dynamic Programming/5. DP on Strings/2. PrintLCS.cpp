/*
Print LCS
*/


//--------- Solution backstracking the tabulation dp

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
		int len = dp[n][m];       //length of lcs
		//creating a dummy ans string 
		string ans="";

		for(int i=0; i<len; i++){
			ans = ans + '$';
		}
		int index = len-1;

		int i=n, j=m; 
		while(i>0 && j>0){
			if(s1[i-1] == s2[j-1]){
				ans[index] = s1[i-1];
				index--;i--;j--;
			}
			else if(dp[i-1][j] >dp[i][j-1])
				i--;
			else
				j--;
		}
		
		return ans;
        

}


string findLCS(int n, int m,string &s1, string &s2){
	
	return f(n, m, s1, s2);	
}