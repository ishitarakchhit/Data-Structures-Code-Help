/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/

//creating a class which contains all the info to be pushed into the heap
class info{
        public:
        int data;
        int row;
        int col;
        info(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
    };
    class compare{
        public:
        bool operator()(info* a, info* b){
            return a->data > b->data;
        }
    };

    //function to perform the solution
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //creating a min heap
        priority_queue<info*, vector<info*>, compare> minheap;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        //inserting the first element of every row into min heap to create a heap of size k
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            info* temp = new info(element, i, 0);
            minheap.push(temp);
        } 
            int start = mini;
            int end = maxi;

        //now pushing the further elements into the heap while popping the topmost element from the heap
        while(!minheap.empty()){
            info* heaptop = minheap.top();
            int topelement = heaptop->data;
            int topRow = heaptop->row;
            int topCol = heaptop->col;
            minheap.pop();

            mini = topelement;                //since this is the minimum element present in the heap 
            int ansrange = end-start;
            int currrange = maxi - mini;

            if( currrange < ansrange){
                start = mini;
                end = maxi;
            }

            if(topCol+1 < nums[topRow].size()){
                maxi = max(maxi, nums[topRow][topCol+1]);
                info* temp = new info(nums[topRow][topCol+1], topRow, topCol+1);
                minheap.push(temp);
            }

            else
                break;
        }

        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};