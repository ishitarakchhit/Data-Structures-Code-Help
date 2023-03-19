/*
[   https://leetcode.com/problems/k-diff-pairs-in-an-array/description/ ]
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Approach: Two pointer approach
    int findPairs(vector<int>& nums, int k) {
        int i=0, j=1;
        set<pair<int,int>> st;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        while(i<n && j<n){
            int diff= nums[j] - nums[i];
            if(diff == k){
                st.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if(diff<k){
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j++;
            }
        }
        return st.size();
    }
};