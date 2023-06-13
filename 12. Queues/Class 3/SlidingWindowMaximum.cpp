/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        vector<int> ans;           //vector to store answer
        deque<int> q;              //deque to store the indices of maxi number of every window 
        int maxi=INT_MIN;
        int index;
        
        //loop to process the first window
        while(i<k){

            //to remove all the elements which are smaller than the current
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();

            //to push the index of current element
            q.push_back(i);

            i++;
        }

        ans.push_back(nums[q.front()]);

        for(int i=k; i<nums.size(); i++){

            //removing the index out of window
            if(!q.empty() &&  i- q.front() >=k ){
                q.pop_front();
            }

            //to remove all the elements which are smaller than the current
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();

            //to push the index of current element
            q.push_back(i);

            //to push the highest element of window into ans
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};