/*
Count all subsets with given sum k in an array arr
*/

int modulo = 1e9 + 7;

int f(vector<int> &arr, int n , int k, vector<vector<int>> &dp){
	if(k == 0) return true;
	if(n == 0) return arr[0] == k;

	if(dp[n][k] != -1) return dp[n][k];

	int notpick = f(arr, n-1, k, dp);

	int pick = 0;
	if(arr[n] <=k)
		pick = f(arr, n-1, k-arr[n], dp);

	dp[n][k] = (pick + notpick)%modulo;
	return dp[n][k];

}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, 0));

	for(int i=0; i<n; i++) dp[i][0] = 1;
	if(arr[0] <=k)
		dp[0][arr[0]] = 1;

	for(int i=1; i<n; i++){
		for(int target = 1; target<=k; target++){
			int notpick = dp[i-1][target];
			int pick = 0;
			if(arr[i] <= target)
				pick = dp[i-1][target-arr[i]];
			dp[i][target] = (pick + notpick)%modulo;
		}
	}
	return dp[n-1][k];
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0);
	vector<int> curr(k+1, 0);
	curr[0] = 1;
	prev[0] = 1;
	if(arr[0] <=k)
		prev[arr[0]] = 1;

	for(int i=1; i<n; i++){
		for(int target = 1; target<=k; target++){
			int notpick = prev[target];
			int pick = 0;
			if(arr[i] <= target)
				pick = prev[target-arr[i]];
			curr[target] = (pick + notpick)%modulo;
		}
		prev = curr;
	}
	return prev[k];
}