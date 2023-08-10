/*
Problem Statement
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
4
10 20 30 10
3
10 50 10
Sample Output 1:
20
0
Explanation Of Sample Input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.
Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 
Sample Output 2:
7
2
*/

#include <bits/stdc++.h>
    int rec(int n, vector<int> &heights){
        if(n == 0)
            return 0;
        
    
        int leftPath  =INT_MAX;
        int rightPath = INT_MAX;

    
        leftPath = abs(heights[n] - heights[n-1]) + rec(n-1, heights);
    

        if(n>1){
            rightPath = abs(heights[n] - heights[n-2]) + rec(n-2, heights);
        }
        return min(leftPath, rightPath);
    }

    int dp1(int n, vector<int> &heights, vector<int> &dp){
        if(n == 0) return 0;

        //if(dp[n] != -1)  return dp[n];
        int leftPath = INT_MAX;
        int rightPath = INT_MAX;

        leftPath = abs(heights[n]- heights[n-1]);
        if(dp[n-1]!=-1) 
            leftPath += dp[n-1];
        else 
            leftPath += dp1(n-1, heights, dp);

        if(n>1){
            rightPath = abs(heights[n]- heights[n-2]);

            if(dp[n-2]!=-1) 
                rightPath += dp[n-2];
            else 
                rightPath += dp1(n-2, heights, dp);
        }
            
        
        dp[n] = min(leftPath, rightPath);
        return dp[n];
    }

    int dp2(int n, vector<int> &heights){
        vector<int> dp(n+1, -1);
        dp[0]  = 0;
        for(int i=1; i<n; i++){
            int leftPath = INT_MAX;
            int rightPath = INT_MAX;

            leftPath = abs(heights[i]- heights[i-1]);
            if(dp[i-1]!=-1) 
                leftPath += dp[i-1];
            else 
                leftPath += dp1(i-1, heights, dp);

            if(i>1){
                rightPath = abs(heights[i]- heights[i-2]);

                if(dp[i-2]!=-1) 
                    rightPath += dp[i-2];
                else 
                    rightPath += dp1(i-2, heights, dp);
            }
            
        
            dp[i] = min(leftPath, rightPath);
        }
        return dp[n-1];
    }

    int sp(int n, vector<int> &heights){
        
        int prev1 = 0;
        int prev2;
        int curr;
        for(int i=1; i<n; i++){
            int leftPath = INT_MAX;
            int rightPath = INT_MAX;

            leftPath = prev1 + abs(heights[i]- heights[i-1]);

            if(i>1){
                rightPath = prev2 + abs(heights[i]- heights[i-2]);
            }
            
        
            curr= min(leftPath, rightPath);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
int frogJump(int n, vector<int> &heights)
{
    //return rec(n-1, heights);

    // vector<int> dp(n+1, -1);
    // return dp1(n-1, heights, dp);

    return dp2(n, heights);
}