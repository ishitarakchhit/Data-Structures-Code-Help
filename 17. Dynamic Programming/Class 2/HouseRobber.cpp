/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/


int rec(vector<int>& nums, int n){
        if(n<0){
            return 0;
        }
        if(n == 0)
            return nums[0];
        
        int include = nums[n] + rec(nums, n-2);
        int exclude = rec(nums, n-1);

        return max(include, exclude);
    }


    //solution using top down approach
    int topDown(vector<int>& nums, int n, vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n == 0)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];
        int include = nums[n] + topDown(nums, n-2, dp);
        int exclude = topDown(nums, n-1, dp);

        dp[n] =   max(include, exclude);
        return dp[n];
    }


    //solution using bottom up approach
    int bottomUp(vector<int> &nums, int n){
        //create dp array
        vector<int> dp(n+1, 0);        //since we wanted to find maximum value we can keep int min but 0 would also serve the purpose
        
        //update base cases
        dp[0] = nums[0];

        //run loop
        for(int i=1; i<=n; i++){
            int include = 0;
            int exclude = 0;
            int temp =0;             //---! mistake_ to handle case with size 2 array

            if(i-2 >=0)
                temp = dp[i-2];

            include = nums[i] + temp;
            exclude = dp[i-1];

            dp[i] =   max(include, exclude);
        }
        return dp[n];
    }



    //space optimisation
    int spaceOpt(vector<int> & nums, int n){
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = prev1;

        //run loop
        for(int i=1; i<=n; i++){
            int include = 0;
            int exclude = 0;
            int temp =0;             //---! mistake_ to handle case with size 2 array

            if(i-2 >=0)
                temp = prev2;

            include = nums[i] + temp;
            exclude = prev1;

            curr =   max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr; 
    }


    int rob(vector<int>& nums) {
        //solution using recursion
        //int ans = rec(nums, nums.size()-1);

        //solution using top down
        // vector<int> dp(nums.size()+1, -1);
        // int ans = topDown(nums, nums.size()-1, dp);

        //solution using bottom up
        //int ans = bottomUp(nums, nums.size()-1);

        //space optimisation
        int ans = spaceOpt(nums, nums.size()-1);

        return ans;
    }