/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Example1:

Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.
Example2:

Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
Expected Space Complexity: O(N)

Constraint:
1 <= N,M <= 100
0 <= edgei,0,edgei,1 < n
0 <= edgei,2 <=105
*/


void topoSort(int node, vector<vector<pair<int,int>>> &graph, vector<bool> &vis, stack<int> &s){
        vis[node] = 1;
        
        for(int j=0; j<graph[node].size(); j++){
            if(!vis[graph[node][j].first])
                topoSort(graph[node][j].first, graph, vis, s);
        }
        
        s.push(node);
        
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> distance(N, INT_MAX);
        
        //to create an adjacency list
        vector<vector<pair<int,int>>>graph(N);
        
        for(int i=0; i<M; i++){
            int node = edges[i][0];
            graph[node].push_back({edges[i][1], edges[i][2]});
        }
        
        
        //to find the topological sort using DFS
        stack<int> s;
        vector<bool> vis(N);
        topoSort(0, graph, vis, s);
        
        distance[0] = 0;
        
        
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            for(int j=0; j<graph[curr].size(); j++){
                int node = graph[curr][j].first;
                int temp = distance[curr] + graph[curr][j].second;
                if(distance[node]> temp)
                    distance[node] = temp;
            } 
            
        }
        
        for(int i=0; i<N; i++){
            if(distance[i] == INT_MAX)
                distance[i] = -1;
        }
        
        return distance;
    } 