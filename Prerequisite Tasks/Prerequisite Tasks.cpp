//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	   
	   //Adjacency List Create Kro
	   vector<int>adj[N];
	   vector<int>indegree(N,0);
	   
	   for(int i =0;i<P;i++){
	    
        int course = prerequisites[i].first;
        int prerequisite = prerequisites[i].second;
        indegree[course]++;

        adj[prerequisite].push_back(course);
	   }
	   
	   //Applying kahn's algorithm
	   //size == N -> no cycle -> Yes
	   //else cycle is present -> No
	   
	   
	   queue<int>q;
	   
	   for(int i =0 ;i<N;i++){
	       if(!indegree[i]){
	           q.push(i);
	       }
	   }
	   
	   int counter = 0; // just using counter instead of a vector to save space 
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       counter++;
	       
	       //Look at the neighbours
	       for(int j= 0; j<adj[node].size();j++){
	           indegree[adj[node][j]]--;
	            if(indegree[adj[node][j]]==0){
	                q.push(adj[node][j]);
	            }
	       }
	       
	      
	   }
	  
	   return counter==N?1:0;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends