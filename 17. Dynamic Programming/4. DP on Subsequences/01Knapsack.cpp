/*
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.

Note: The thief is not allowed to break the items.

For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

Input Format:
The first line contains a single integer 'T' representing the number of test cases.      
The 'T' test cases are as follows:

The first line contains two integers 'N' and 'W', denoting the number of items and the maximum weight the thief can carry, respectively. 
The second line contains 'N' space-separated integers, that denote the values of the weight of items. 
The third line contains 'N' space-separated integers, that denote the values associated with the items. 
Output Format :
The first and only line of output contains the maximum profit that a thief can generate, as described in the task. 
The output of every test case is printed in a separate line.
Constraints:
1 <= T <= 10
1 <= N <= 10^3
1 <= W <= 10^3
1<= weights <=10^3
1 <= values <= 10^3


where 'T' is the number of test cases, ‘N’ is the number of items, "weights" is the weight of each item, "values" is the value of each item and ‘W’ is the maximum weight the thief can carry. 
*/


// int f(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp){
// 	if(n==0){
// 		if(weight[0] <= maxWeight)
// 			return value[n];
// 		else return 0;
	
// 	}

// 	if(dp[n][maxWeight] != -1) return dp[n][maxWeight];

// 	int notpick = f(weight, value, n-1, maxWeight, dp);
// 	int pick = 0;
// 	if(weight[n] <= maxWeight)
// 		pick = value[n] + f(weight, value, n-1, maxWeight-weight[n], dp);
// 	dp[n][maxWeight] = max(pick, notpick);
// 	return dp[n][maxWeight];
// }

int f(vector<int> &weight, vector<int> &value, int n, int maxWeight){
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	for(int i=weight[0]; i<=maxWeight; i++){	dp[0][i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int w=0; w<=maxWeight; w++){
			int notpick = dp[i-1][w];
			int pick = INT_MIN;
			if(weight[i] <= w )
				pick = value[i] +dp[i-1][w-weight[i]];
			dp[i][w] = max(pick, notpick);
		}
	}

	return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	//return f(weight, value, n, maxWeight);

	vector<int> prev(maxWeight+1, 0);
	//vector<int> curr(maxWeight+1, 0);

	for(int i=weight[0]; i<=maxWeight; i++){	prev[i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int w=maxWeight; w>= 0; w--){
			int notpick = prev[w];
			int pick = INT_MIN;
			if(weight[i] <= w )
				pick = value[i] + prev[w-weight[i]];
			prev[w] = max(pick, notpick);
		}
		//prev = curr;
	}

	return prev[maxWeight];
}