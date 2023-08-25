/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/


/*
    bool f(vector<int> &nums, int sum, int n, vector<vector<int>> &dp){
        
        if(sum == 0) return true;
        
        if(n==0) 
            return nums[0]==sum;

        if(dp[n][sum] != -1) return dp[n][sum]; 

        //not pick
        bool notpick = f(nums, sum, n-1, dp);
        
        //pick
        bool pick = false;
        if(nums[n] <= sum)
            pick = f(nums, sum-nums[n], n-1, dp);
        

        return pick || notpick;
        
    }*/

    bool f(vector<int> &nums, int sum , int n){
        vector<bool> prev(sum+1, false);
        vector<bool> curr(sum+1, false);
        //base cases
        prev[0] = true;
        curr[0] = true;
        if(nums[0] <= sum)
            prev[nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int target = 1; target<=sum; target++){
                //not pick
                //if(i-1 >= 0)
                bool notpick = prev[target];
                
                //pick
                bool pick = false;
                if(nums[i] <= target)
                    pick = prev[target-nums[i]];

                curr[target] = pick | notpick; 
            }
            prev = curr;
        }
        //cout<<n<<" "<<nums.size()-1<<" "<<dp.size()<<" "<<dp[0].size();
        return curr[sum];

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums) sum+=i;
        
        if(sum&1 || nums.size()==1) return false;

        int n = nums.size();
        sum/=2;
        //vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return f(nums, sum, n);
    }