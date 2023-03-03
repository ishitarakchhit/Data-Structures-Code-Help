 
 /*
[https://leetcode.com/problems/spiral-matrix/submissions/872552508/]
 Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:
         1 2 3 
         4 5 6
         7 8 9

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
         1  2  3  4
         5  6  7  8
         9 10 11 12

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 */
 
/*Approach: 
print start column to end column
print start row to end row
print end column to start column
print end row to start row

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row= matrix.size();
        int col= matrix[0].size();
        int total= row*col;
        int count =0; 

        //index initialization
        int startrow=0;
        int startcol=0;
        int endrow=row-1;
        int endcol=col-1;

        while(count < total){
            for(int i=startcol; i<=endcol && count<total; i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;

            for(int i=startrow; i<=endrow && count<total; i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;

            for(int i=endcol; i>=startcol && count<total; i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;

            for(int i=endrow; i>=startrow && count<total; i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};