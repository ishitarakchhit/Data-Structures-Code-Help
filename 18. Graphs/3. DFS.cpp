//function to perform dfs
    void dfs(vector<int> adj[], int V, vector<bool>&vis, vector<int> &ans){
        ans.push_back(V);
        vis[V] = 1;
        
        for(auto &x: adj[V]){
            if(!vis[x]){
                dfs(adj, x, vis, ans);
            }
        }
        return;
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<int> ans;
        dfs(adj, 0, vis, ans);
        return ans;
    }