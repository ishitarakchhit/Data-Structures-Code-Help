/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

int func(vector<int> & nums, int n){
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = prev1;

        //run loop
        for(int i=1; i<n; i++){
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
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> arr1;
        vector<int> arr2;

        for(int i=0; i<n-1; i++){
            arr1.push_back(nums[i]);
        }

        for(int i=1; i<n; i++){
            arr2.push_back(nums[i]);
        }
        
        return max(func(arr1, n-1), func(arr2, n-1));
    }