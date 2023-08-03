/*
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 105
*/



 bool canPush(vector<int> &ans, int &top){
        for(auto it:ans){
            if(it == top)
                return false;
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> maxheap;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                //pushing one grid element
                    maxheap.push(grid[i][j]);

                //now finding all related rhombuses taking current grid element as center
                //Let's check if the current element is the edge of grid or not
                //when it is the edge element we cannot create a rhombus
                if(i==0 || j==0 || i==grid.size()-1 || j== grid[0].size()-1) 
                    continue;
                
                //now create rhombuses from no edge elements
                else{
                    int delta =1;
                    
                    //mistake---! did not add all the conditions, upper limit I forgot to check
                    while(i-delta>=0 && j-delta>=0 && delta+i < grid.size() && delta+j <grid[i].size()){
                        //finding the vertices of rhombus
                        int a1 = i-delta;
                        int b1 = j;

                        int a2 = i;
                        int b2 = j+delta;
                        
                        int a3 = i+delta;
                        int b3 = j;
                        
                        int a4 = i;
                        int b4 = j-delta;

                        int sum = 0;

                        //now finding the sum considering vertices and all grid cells between vertices

                        //to find the sum from top point to right point "\"
                        for(int v1=a1, v2=b1; v1<a2 && v2<b2; ){
                            sum += grid[v1++][v2++];
                        }
                        
                        //to find the sum from right to bottom line "/"
                        for(int v1=a2, v2=b2; v1<a3 && v2>b3; ){
                            sum += grid[v1++][v2--];
                        }

                        //to find the sum from bottom to left "\"
                        for(int v1=a3, v2=b3; v1>a4 && v2>b4; ){
                            sum += grid[v1--][v2--];
                        }

                        //to find the sum from left to top "/"
                        for(int v1=a4, v2=b4; v1>a1 && v2<b1; ){
                            sum += grid[v1--][v2++];
                        }

                        //if the current rhombus sum is greater than top element of heap then push it 
                        maxheap.push(sum);

                        delta ++;
                    }
                }

            }
        }

        //vector to store the answer
        vector<int> ans;
        
        ans.push_back(maxheap.top());
        maxheap.pop();

        //loop to push all distinct elemnts from heap to array
        //mistake----! got stuck here.
        while (!maxheap.empty() && ans.size() < 3) {
            int top = maxheap.top();
            maxheap.pop();

            if(canPush(ans, top))
                ans.push_back(top);

        }    
    
        return ans;
    }