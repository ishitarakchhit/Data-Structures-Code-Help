/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution {
    //function to find the previous smaller element in an array
    vector<int> prevSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());

    for (int i=0; i<arr.size(); i++)
    {
        
            while(s.top()!=-1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
                ans[i] = s.top();
                s.push(i);
        
    }
    
    return ans;
}

//function to find the next smaller element in an array
vector<int> nextSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());

    for (int i = arr.size()-1; i>=0; i--)
    {
        
            while(s.top()!=-1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
                ans[i] = s.top();
                
                    
                s.push(i);        
    }
    
    return ans;
}


//function to find the max area and return answer
//traversing the array of histrogram and extending the line towards left and right and then calculating the area the falls between using width and then finding the area
int findmaxarea(vector<int> &arr){
    int maxarea=INT_MIN;
    vector<int> prev = prevSmallerElement(arr);
    vector<int> next = nextSmallerElement(arr);

    for (int i = 0; i < arr.size(); i++)
    {   if(next[i] == -1){
        next[i] = arr.size();
    }
        int n= next[i];
        int p = prev[i];
        int width = n-p-1;
        int area = width* arr[i];
        maxarea= max(maxarea, area);
    }
    return maxarea;

}


public:

    //function to find the maximal rectangle area
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();

        //to convert all elements from char matrix to int matrix
        for(int i=0; i<n; i++){
            vector<int> arr;
            for(int j=0; j<m; j++){
                arr.push_back(matrix[i][j]-'0');
            }
            v.push_back(arr);
        }
        
        //loop to make histograms particular to every row and then pass the row as parameter in f call to find max area among histograms
        int area = findmaxarea(v[0]);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]){
                    v[i][j]+= v[i-1][j];
                }
                else
                    v[i][j] = 0;
            }

            //to find max area among all row hitograms
            area = max(area, findmaxarea(v[i]));
        }
        return area;
    }
};