/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
Example 2:

Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= A[] <= 1
*/

int maxLen(int arr[], int N)
    {
        
        unordered_map<int, int> map;
        
        int maxLength =0; 
        int currSum = 0;

        //replacing all 0s with -1 then it will give sum 0 when equal no.s of 0s and 1s are encountered
        for(int i=0; i<N; i++){
            int val;

            if(arr[i] == 0)
                val = -1;
            else
                val = 1;
            currSum+= val;
            
            if(currSum == 0)
                maxLength = max(maxLength, i + 1);
            
            else if( map.find(currSum) == map.end())
                map[currSum] = i;

            else
                maxLength = max(maxLength, i- map[currSum]);
                
            
        }
        
        return maxLength;
    }