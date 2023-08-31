/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next 2 * T lines represent the ‘T’ test cases.

The first line of each test case contains an integer ‘N’ denoting the length of the rod.

The second line of each test case contains a vector ’A’, of size ‘N’ representing the cost of different lengths, where each index of the array is the sub-length and the element at that index is the cost for that sub-length.
Note:

Since 1-based indexing is considered, the 0th index of the vector will represent sub-length 1 of the rod. Hence the (N - 1)th index would represent the cost for the length ‘N’. 
Output Format
For each test case, print a single line that contains a single integer which is the maximum cost obtained by selling the pieces.

The output of each test case will be printed in a separate line.
Note:

You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
*/


/*
int f(vector<int> &price, int n, int rod, vector<vector<int>> &dp){
	if(n==0){
		if(rod % 1 == 0) 
			return rod*price[0];
		else 
			return -1e9; 
	}

	if(dp[n][rod] != -1) return dp[n][rod];

	//not using the current mark to cut
	int notcut = f(price, n-1, rod, dp);

	//using the current mark to cut
	int cut = 0;
	if(rod-n-1 >= 0)
		cut = price[n] + f(price, n, rod-n-1, dp);
	
	dp[n][rod] = max(cut, notcut);
	return dp[n][rod];
}


int f(vector<int> &price, int &n, int &rod){
	vector<vector<int>> dp(n, vector<int>(rod+1, 0));

	for(int r = 0; r<=rod; r++){
		dp[0][r] = r*price[0];
	}

	for(int i=1; i<n; i++){
		for(int r=1; r<=rod; r++){
			int notcut = dp[i-1][r];

			int cut = 0;
			if(r-i-1 >=0)
				cut = price[i] + dp[i][r-i-1];
			dp[i][r] = max(cut, notcut);
		}
	}
	return dp[n-1][rod];
}


int f(vector<int> &price, int &n, int &rod){
	vector<int> prev(rod+1, 0);
	vector<int> curr(rod+1, 0);

	for(int r = 0; r<=rod; r++){
		prev[r] = r*price[0];
	}

	for(int i=1; i<n; i++){
		for(int r=1; r<=rod; r++){
			int notcut = prev[r];

			int cut = 0;
			if(r-i-1 >=0)
				cut = price[i] + curr[r-i-1];
			curr[r] = max(cut, notcut);
		}
        prev = curr;
		
	}
	return prev[rod];
}
*/

//further sp opt
int f(vector<int> &price, int &n, int &rod){
	//vector<int> prev(rod+1, 0);
	vector<int> curr(rod+1, 0);

	for(int r = 0; r<=rod; r++){
		curr[r] = r*price[0];
	}

	for(int i=1; i<n; i++){
		for(int r=1; r<=rod; r++){
			int notcut = curr[r];

			int cut = 0;
			if(r-i-1 >=0)
				cut = price[i] + curr[r-i-1];
			curr[r] = max(cut, notcut);
		}
        
		
	}
	return curr[rod];
}