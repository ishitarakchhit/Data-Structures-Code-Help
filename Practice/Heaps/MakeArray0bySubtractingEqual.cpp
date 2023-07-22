/*

*/
//approach 1: brute force
int findsmallestnonzero(vector<int> &nums){
        int smallest = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < smallest && nums[i] != 0)
                smallest = nums[i];
        }
        return smallest;
    }

    int minimumOperations(vector<int>& nums) {
        int count = 0;
        while(*max_element(nums.begin(), nums.end()) > 0){
            int smallest = findsmallestnonzero(nums);
            count ++;
            for(int i =0; i<nums.size(); i++){
                if(nums[i] != 0)
                    nums[i]-= smallest;
            }
        }
        return count;

    }


//Approach2: using max heap: we are trying to count the number of operations by placing the same number of element into the max heap. So that the numbers in the heap don't repeat we will compare it with the top element and the array will be soted initially
int minimumOperations(vector<int>& nums) {
        priority_queue<int> q;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if((nums[i]!=0 && !q.empty() && nums[i]!= q.top()) || (nums[i]!=0 && q.empty()))
                q.push(nums[i]);
        }

        return q.size();
    }