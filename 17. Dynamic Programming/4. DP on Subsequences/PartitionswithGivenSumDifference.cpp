/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
*/


#include <bits/stdc++.h> 
int modulo = 1e9 +7;

int f(vector<int> &arr, int n , int k, vector<vector<int>> &dp){
	if(n == 0){
        if(k==0 && arr[0] == 0) return 2;
        if(k==0 || k==arr[0]) return 1;
        return 0;
    }

	if(dp[n][k] != -1) return dp[n][k];

	int notpick = f(arr, n-1, k, dp);

	int pick = 0;
	if(arr[n] <=k)
		pick = f(arr, n-1, k-arr[n], dp);

	dp[n][k] = (pick + notpick)%modulo;
	return dp[n][k];

}

int findWays(vector<int> &arr, int k){
    int n =arr.size();
    vector<int> prev(k+1, 0);
    vector<int> curr(k+1, 0);
    
    if(arr[0] == 0) prev[0] =2;
    else prev[0] = 1;
    
    if( arr[0]!=0 && arr[0] <=k ) prev[arr[0]] = 1;
 
    for(int i=1; i<n; i++){
        for(int target = 0; target<=k; target++){
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

int countPartitions(int n, int d, vector<int> &arr) {
    int k=0;
    for(auto i:arr) k+=i;
	
    if(k-d <0 || (k-d)%2) return false;
    
    return findWays(arr, (k-d)/2); 
    
}


