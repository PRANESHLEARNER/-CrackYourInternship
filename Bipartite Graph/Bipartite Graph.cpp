//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>col(V);
	   vector<bool>vis(V,false);
	   
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           if(dfs(-1,i,adj,vis,col)==false)return false;
	       }
	   }
	   
	   return true;
	}
	
	bool dfs(int parent ,int node ,vector<int>adj[],vector<bool> &vis,vector<int> &col){
	    
	    vis[node]=true;
	    if(parent !=-1 ){
	        col[node]=!col[parent];
	    }
	    if(parent==-1){
	        col[node]=0;
	    }
	    
	    for(auto & nextNode : adj[node]){
	        if(!vis[nextNode]){
	           if(dfs(node,nextNode,adj,vis,col)==false) return false;
	        }
	        else if( col[node]==col[nextNode]){
	            return false;
	        }
	    }
	    
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends