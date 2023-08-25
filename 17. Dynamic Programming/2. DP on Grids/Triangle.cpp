/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/

/*
    int f(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
        if(i>= triangle.size() || j >= triangle[i].size()) return 0;

        if(i== triangle.size()-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX, diagonal = INT_MAX;

        down = triangle[i][j] + f(triangle, i+1, j, dp);

        diagonal = triangle[i][j] + f(triangle, i+1, j+1, dp);

        dp[i][j] = min(down, diagonal);
        return dp[i][j];
    }*/

    int f(vector<vector<int>> &triangle){
        vector<int> dp(triangle.size(), INT_MAX);
        vector<int> temp(triangle.size());
        for(int i=0; i<triangle.size(); i++){
            for(int j=0; j<triangle[i].size(); j++){
                if( i==0 && j==0){
                    dp[j] = triangle[i][j];
                    continue;
                }

                int down = INT_MAX, diagonal = INT_MAX;
                
                if(i-1 >=0 && j< triangle[i].size()-1)   //since we cannot go the upper element when we are at the last element of a row
                    down = triangle[i][j] + temp[j];

                if(i-1 >=0 && j-1 >= 0)
                    diagonal = triangle[i][j] + temp[j-1];

                dp[j] = min(down, diagonal);
            }
            temp = dp;
        }

        int ans = INT_MAX;
        int n = dp.size();
        for(int i=0; i<n; i++){
            if(dp[i] != INT_MAX){
                ans = min(ans, dp[i]);
            }
        }

        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0;    //first row
        int j=0;    //first row first element
        //vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return f(triangle);
    }
};