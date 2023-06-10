/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> temp;
        stack<int> st;
        //pusing INT_MAX so that in case of no next greater element we use INT_MAX which is further converted to -1(as per ques)
        st.push(INT_MAX);
        int i = nums.size()-1;

        //to push all elements from nums array to stack in reverse order so that we can find the elements for cicular array
        while(i>=0){
            st.push(nums[i--]);
        }
        i = nums.size()-1;

        //loop to find the next greater element for nums array 
        while(i>=0){

            //when st.top() > nums[i] that means we have found the next greater element
            if(st.top() > nums[i]){
                temp.push_back(st.top()==INT_MAX?-1: st.top());                  //when greater element is INT_MAX then push -1 instead of INT_MAX
            }

            //if not then pop elements from stack until we find greater element
            else{
                while(!st.empty() && st.top()<= nums[i]){
                    st.pop();
                }

                temp.push_back(st.top()==INT_MAX?-1: st.top());
            }
            st.push(nums[i]);
            i--;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};