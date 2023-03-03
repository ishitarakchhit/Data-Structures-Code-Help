/*
[   https://leetcode.com/problems/find-the-duplicate-number/submissions/907907731/  ]

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/
#include<bits/stdc++.h>
using namespace std;


//Approach 1: marking method
class Solution {

public:
    int findDuplicate(vector<int>& nums) {
        int ans;

        //modifies each element with absolute value of element when the array hasn't already been modified
        int index;
        for(int i=0; i<nums.size(); i++){
            int index= abs(nums[i]);   
            if(nums[index] <0){
                ans= index;   
                break;     
            }

            nums[index]*=(-1);
        }
         
        return ans;
    }
};


//Approach 2: Sorting method
/*
class Solution {

public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1])
                ans=  nums[i];
        }
        return ans;
    }
};
*/

//Approach 3: move all elements so that same index represents same element. The element which would be left in the 0th index will be the extra or duplicate element
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};
*/
