vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        
        vector<bool> vis(V, 0);     //to mark all the visited elements
        vis[0] = 1;
        
        vector<int> ans;             //to store the traversal
        
        while(!q.empty()){
            int front = q.front();     //pop the element from queue
            q.pop();                
            ans.push_back(front);       //store in ans array
            
            for(int &x:adj[front]){     //push all its direct vertices into q if not visited
                if(vis[x] == 0){
                    q.push(x);
                    vis[x] = true;      //mark it to be visited
                }
            }
        }
        return ans;
    }