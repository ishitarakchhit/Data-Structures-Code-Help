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


bool isCyclic(int V, vector<int> adj[]) {
         
        vector<int> indegree(V, 0);
        queue<int> q;
        int count = 0;
        
        //to store the indegree of all nodes
        for(int i=0; i<V; i++){
            for(auto &node: adj[i])
                indegree[node]++;
        }
        
        
        //to push all nodes with indegree 0
        for(int i=0; i<V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        //to find the topo sort
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            // to remove all the dependencies of currently removed nodes from queue
            for(auto &x: adj[node]){
                indegree[x]--;
                if(indegree[x] == 0)     //meanwhile if we encounter indegree 0 nodes push it into the queue
                    q.push(x);
            }
        }
        
        if(count == V) return 0;
        else return 1;
         
    }