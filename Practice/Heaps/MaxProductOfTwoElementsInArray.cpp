/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

int maxProduct(vector<int>& nums) {
        //Approach1: using max heap: Tn = O(n^2 log(n)) and space O(n)
        priority_queue<int> maxheap;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i!=j){

                int element= (nums[i]-1)*(nums[j]-1);
                maxheap.push(element);
                }
            }
        }
        return maxheap.top();

        //Approach2: sorting the array: Tn = O(nlog(n)) and space O(1)
        // sort(nums.begin(), nums.end());
        // return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);

        //Another approach: You can find the maximum element and 2nd max element fron the array using max element function and min heap and then then return the ans, this will take time complexity as O(n) + O(nlog(2)) and space of O(2) i.e. constant
    }