/**/


/*
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k = 0;
        for(auto i:arr) k+= i;
	
	vector<vector<bool>> dp(n, vector<bool> (k+1, false));

        //setting the base cases
        //when target == 0 every index of array will return true
        for(int i=0; i<n; i++) dp[i][0] = true;
        
        //when we are at 0th index and target == arr[0] return true;
        if(arr[0] <= k)
            dp[0][arr[0]] = true;
        

        //run loops
        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool notpick = dp[i-1][j];
                bool pick = false;
                if(arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];

                dp[i][j] = pick | notpick;

            }
        }
        
        //now try finding min difference subsets
        int ans = INT_MAX;
        for(int target=0; target<=k; target++){
            if(dp[n-1][target] == true)
                ans = min(ans, abs(target- k+target));
        }
        return ans;

}
*/



