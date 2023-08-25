/*
Problem Statement
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation Of Sample Input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210.
Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11
Sample Output 2:
45
110

*/

// int func(vector<vector<int>> &points, int n, int j, vector<vector<int>> &dp){
//     if(n==0){
//         int maxi =0;
//         for(int i=0; i<3; i++){
//             if(i!=j){
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
//         return maxi;
//     }
//     if(j<3)
//     if(dp[n][j] != -1) return dp[n][j];
    
//     int maxi = 0;
//     for(int i=0; i<3; i++){
//         if(i!=j){
//             maxi = max(maxi, points[n][i] + func(points, n-1, i, dp));
//         }
//     }
//     dp[n][j] = maxi;
//     return dp[n][j];
// }

int func(vector<vector<int>> &points, int n, int j){
    vector<int> dp(3, -1);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for(int day = 1; day<=n; day++){
            vector<int> temp(4, 0);
        for(int last = 0; last<=3; last ++){
            int maxi = 0;
            for(int i=0; i<3; i++){
              if (i != last) {
                temp[last] = max(temp[last], points[day][i] + dp[i]);
              }
            }
        }
            dp=temp;
    }
    return dp[3];
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    int j = 3;
    return func(points, n-1, j);
}