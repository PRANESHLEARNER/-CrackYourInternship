//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>arr, int k) 
    { 
        // Code here
        int n=arr.size();
        int cost[n][n];
        
        for(int i=0;i<n;i++){
            cost[i][i]=k-arr[i];
            for(int j=i+1;j<n;j++){
                cost[i][j]=cost[i][j-1]-arr[j]-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j==n-1 && cost[i][j]>0){
                    cost[i][j]=0;
                }
                if(cost[i][j]<0)cost[i][j]=INT_MAX;
                else cost[i][j]=cost[i][j]*cost[i][j];
            }
        }
        int min[n];
        for(int i=n-1;i>=0;i--){
            min[i]=cost[i][n-1];
            
            for(int j=n-1;j>i;j--){
                if(cost[i][j-1]==INT_MAX)continue;
                if(min[i]>cost[i][j-1]+min[j]){
                    min[i]=cost[i][j-1]+min[j];
                }
            }
    } 
    return min[0];
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends