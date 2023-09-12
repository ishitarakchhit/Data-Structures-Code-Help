#include<iostream>
#include<vector>
using namespace std;

/*
//adjacency matrix
int main(){
    int n, m;
    cout<<"Enter nodes and edge sizes: ";
    cin>>n>>m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout<<endl<<"Printing the adjacency matrix"<<endl;
    //to print the adj matrix
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


//adjacency list
int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for (int i = 0; i <m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to print the adjacency list
    for(int i = 0; i<=n; i++){
        cout<<i<<"->";
        for(auto &x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}