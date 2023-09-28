/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105


*/


bool bfs(int V, vector<int>adj[], vector<int> &mark){
        queue<int> q;
	    q.push(V);
	    mark[V] = 0;
	    
	    while(!q.empty()){
	        int element = q.front();
	        q.pop();
	        bool color = mark[element];
	        
	        for(auto &x: adj[element]){
	            //if we have already coloured the current element
	            if(mark[x] != -1){
	                if(mark[x] == color) return false;
	            }
	            else{
	                mark[x] = !color;
	                q.push(x);
	            }
	            
	        }
	    }
	    
	    return true;
    }
public:

    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> mark(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(mark[i] == -1){
	          int ans = bfs(i, adj, mark);
	          if(ans == false) return false;
	        } 
	    }
	    
	    return true;
	    
	}