/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/




//-----------------Solution--------------------



void bfs(vector<vector<int>>& image, int sr, int sc, int &color, int &oldcolor){
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int dx=-1; dx<=1; dx++){
                for(int dy=-1; dy<=1; dy++){
                    if(abs(dx) != abs(dy)){
                        if(row+dx >=0 && row+dx <n && col+dy >=0 && col+dy <m){
                            if(image[row+dx][col+dy] == oldcolor){                  //depicts that current element is not visited
                                q.push(make_pair(row+dx, col+dy));
                                image[row+dx][col+dy] = color;
                            }
                        }
                    }
                }
            }
        }
    }

    
    void dfs(vector<vector<int>>& image, int row, int col, int &color, int &oldcolor){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;
        
        for(int dx=-1; dx<=1; dx++){
            for(int dy=-1; dy<=1; dy++){
                if(abs(dx) != abs(dy)){
                    if(row+dx >=0 && row+dx <n && col+dy >=0 && col+dy <m){
                        if(image[row+dx][col+dy] == oldcolor){                  //depicts that current element is not visited           
                            dfs(image, row+dx, col+dy, color, oldcolor);
                        }
                    }
                }
            }
        }
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(image[sr][sc] != color)
            dfs(image, sr, sc, color, oldcolor);
        return image;
    }