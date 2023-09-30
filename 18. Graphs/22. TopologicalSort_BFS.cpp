vector<int> topoSort(int V, vector<int> adj[]) 
	{   vector<int> ans;
	    vector<int> indegree(V, 0);
	    queue<int> q;
	    
	    //sotring indegree for all nodes
	    for(int i=0; i<V; i++)
	        for(auto &node: adj[i])
	            indegree[node]++;
	        
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto &it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it);
	        }
	        
	    }
	    
	    
	    return ans;
	    
	}