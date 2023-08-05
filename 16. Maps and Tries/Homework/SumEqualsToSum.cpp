/*
Given an array A of N integers. The task is to find if there are two pairs (a, b) and (c, d) such that a+b = c+d.

Example 1:

Input:N=7 A[] = {3, 4, 7, 1, 2, 9, 8} Output: 1Explanation:(3, 7) and (9, 1) are the pairs whosesum are equal.  

Example 2:

Input:N=7 A[] = {65, 30, 7, 90, 1, 9, 8}Output: 0
 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findPairs() that takes array a and nas parametersand return 1 if pair exists else 0.


Expected Time Complexity:O(N2).
Expected Auxiliary Space:O(N2).

Constraints:
1 ≤ N ≤ 103
*/

int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<long long , bool> mp; // we are hashing pair sum with pairs
        
        for(long long i=0; i<n ;i++){
            for(long long j=i+1; j<n; j++){
                long long sum = a[i] + a[j];
                
                if(mp[sum]){
                    return 1;
                }
                mp[sum] = true;
            }
        }
        return 0;
        
    }