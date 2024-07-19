//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
	public:
	void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
	    vis[u] = true;
	    for (int &v : adj[u]) {
	        if (!vis[v]) {
	            dfsFill(v, adj, vis, st);
	        }
	    }
	    st.push(u);
	}
	
	void dfsTraversal(int u, vector<vector<int>> &adj, vector<bool> &vis) {
	    vis[u] = true;
	    for (int &v : adj[u]) {
	        if (!vis[v]) {
	            dfsTraversal(v, adj, vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsFill(i, adj, vis, st);
            }
        }
        
        vector<vector<int>> revAdj(V);
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                revAdj[v].push_back(u);
            }
        }
        
        int countSCC = 0;
        vis = vector<bool>(V, false);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                dfsTraversal(node, revAdj, vis);
                countSCC++;
            }
        }
        return countSCC;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends