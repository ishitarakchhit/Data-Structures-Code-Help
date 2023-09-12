/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/


//----------------------Solution--------------------


void traversal(vector<vector<int>> &isConnected, vector<bool> &vis, int &V){
        int n = isConnected.size();
        queue<int> q;
        q.push(V);
        vis[V] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int i = 1; i<=n ; i++){
                if(vis[i] == 0){
                    if(isConnected[front-1][i-1] == 1 && front!=i){

                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        return;
    }

    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int &V){
        
        vis[V] = 1;
        
        for(int i=1; i<=isConnected.size(); i++){
            if(!vis[i]){
                if(isConnected[V-1][i-1] == 1){
                    dfs(isConnected, vis, i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n+1, 0);
        int ans =0;

        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                dfs(isConnected, vis, i);
                for(auto i:vis) cout<<i<<" ";
                ans++;
            }
        }
        return ans;
    }