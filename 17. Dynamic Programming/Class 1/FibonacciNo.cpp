class Solution {
public:

    //Recursive solution
    int rec(int n){
        //Base Case
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        return rec(n-1) + rec(n-2);        //RR
    }

    //DP- Top Down approach 
    int topDown(int n, vector<int> &dp){
        //Base Case
        if(n == 0)
            return 0;

        if( n == 1)
            return 1;

        //checking if corresponding value already exists
        if(dp[n] != -1)
            return dp[n];
        
        //otherwise calculating the current value
        
        dp[n] = topDown(n-1, dp) + topDown(n-2, dp);
        return dp[n];
        

    }

    //DP: using bottomUP approach
    int bottomUP(int n){
        //Step 1: create a dp array
        vector<int> dp(n+1, -1);

        //Now find the base cases and store the value in dp array
        dp[0] = 0;
        if(n == 0)
            return dp[0];
        dp[1] = 1;

        //Now run a loop idenfing the starting and ending points
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        //returning the answer
        return dp[n];
    }


    //DP: space optimising since we only require two previus values to calculate the current value of n, identified using RR
    int spaceopt(int n){
        //base cases
        if(n == 0)  return 0;
        if(n == 1)  return 1;

        int prev1 = 1;
        int prev2 = 0;
        int curr;

        //running a loop
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;           //using variables or any other thing instead of dp array
            prev2 = prev1;
            prev1 = curr;
        }

        //return the answer
        return curr;
    
    }

    int fib(int n) {
        //return rec(n);


        //Solving for top Down approach
        //Step1: create DP array and initialize it with a certain value
        vector<int> dp(n+1, -1);
        //return topDown(n,dp);

        //return bottomUP(n);

        return spaceopt(n);
    }
};