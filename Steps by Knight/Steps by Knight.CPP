//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{   private:
    bool isPossible(int n,pair<int,int> p,unordered_map<int,unordered_map<int,bool>>& m){
            return (p.first<=n && p.first>0) && (p.second<=n && p.second>0) && !m[p.first][p.second];
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    if(KnightPos==TargetPos){
	        return 0;
	    }
	    vector<vector<int>> help={{1,2},{2,1},{1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2,-1}};
	    queue<pair<pair<int,int>,int>> q; 
	    
	    q.push(make_pair(make_pair(KnightPos[0],KnightPos[1]),0));
	    
	    unordered_map<int,unordered_map<int,bool>> m;
	    
	    m[KnightPos[0]][KnightPos[1]]=true;
	    
	    while(!q.empty()){
	    
	        pair<pair<int,int>,int> temp=q.front();
	        
	        int i=temp.first.first;
	        
	        int j=temp.first.second;
	        
	        q.pop();
	    
	        for(auto x:help){
	           
	            pair<int,int> test = make_pair(i+x[0],j+x[1]);
	            
	            if(test.first==TargetPos[0] && TargetPos[1]==test.second){
                    return temp.second+1;
                }
                
	            if(isPossible(N,test,m)){
	       
                    q.push(make_pair(test,temp.second+1));
                    
                    m[test.first][test.second]=true;
                
	            }
	            
	        }
	    }
	    return -1;
	    
	    
	    
	}
};

//{ Driver Code Starts.

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends