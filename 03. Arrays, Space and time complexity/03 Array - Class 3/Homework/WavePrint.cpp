 
 /*
[https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=0]
 You are given a 2-D array. Store all the elements from the array to another vector in sin wave form. top to down then down to top and so on.
 eg: 1 2 3 4 
     5 6 7 8 
     9 1 2 3 
 should be printed as {1, 5, 9, 1, 6, 2, 3, 7, 2, 3, 8, 4}
 */
 
 //Approach: for even index in column top-> bottom and for odd index in column bottom-> top
 
 #include <bits/stdc++.h> 
 using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;
    
    for(int j=0; j<mCols; j++){
        //for even index top-> bottom
        if(j%2 == 0){
            for(int i=0; i<nRows; i++){
                ans.push_back(arr[i][j]);
            }
        }
        //for odd index bottom-> top
        else{
             for(int i=nRows-1; i>=0; i--){
                ans.push_back(arr[i][j]);
             }
        }
    }
    return ans;
}
 