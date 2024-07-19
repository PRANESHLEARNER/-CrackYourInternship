//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,int vis[],vector<int>adj[],int recStack[]){
        vis[node] = 1;
        recStack[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,recStack)==true)
                    return true;
            }
            else if(recStack[it]){
                return true;
            }
        }
        recStack[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        int recStack[V];
        for(int i=0;i<V;i++) vis[i] = 0;
        for(int i=0;i<V;i++) recStack[i] = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,recStack)==true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends