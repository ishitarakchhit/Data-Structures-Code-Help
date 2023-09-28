/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
*/



bool dfs(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &mark){
        mark[i] = 1;
        vis[i] = 1;
        for(const auto &x: adj[i]){
            
            if(mark[x] == 1) return true;
            if(vis[x] == 0)
                if(dfs(x, adj, vis, mark) == 1) return true;
            
        }
        mark[i] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
         vector<bool> vis(V, 0);
        //return true;
         for(int i=0; i<V; i++){
             if(vis[i] == 0){
                 vector<bool> mark(V, 0);
                 vis[i] = 1;
                 //cout<<i<<endl;
                 if(dfs(i, adj, vis, mark)) return true;
             }
         }
         return false;
         
         
    }