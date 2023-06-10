/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
*/

class Solution {
public:
    //Approach1: using stacks and storing next greater element for every from nums2 in temporary array
    //Approach2: using stacks and storing next greater element for every from nums2 in map so as to directly access the next greater element when we are traversing through nums1
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> temp;
        stack<int> st;
        st.push(INT_MAX);
        int i = nums2.size()-1;

        //loop to find the next greater element for nums2 array
        while(i>=0){
            if(st.top() > nums2[i]){
                temp.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top()<= nums2[i]){
                    st.pop();
                }
                temp.push_back(st.top());
            }
            st.push(nums2[i]);
            i--;
        }
        reverse(temp.begin(), temp.end());
    
        //loop to find the same element in nums2 from nums1 then pushing it into ans array.
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    if(temp[j] == INT_MAX)
                        temp[j] = -1;
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};