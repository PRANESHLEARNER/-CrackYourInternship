//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
   
    
    int brute(vector<vector<int>>& grid, int n)
    {
        vector<int>row(n,0),col(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(row[i]==0 && col[i]==n-1) return i; 
        }
        return -1;
        
        // Time : O(N*N) + O(N)
    }
    
    int optimised(vector<vector<int>>& grid, int n)
    {
        int top=0, bottom=n-1;
        while(top<bottom)
        {
            if(grid[top][bottom]==1) top++;
            else if(grid[bottom][top]==1) bottom--;
            else{
                top++;
                bottom--;
            }
        }
        
        if(top>bottom) return -1;
        for(int i=0;i<n;i++){
            if(grid[top][i]!=0) return -1;
            if(i!=top && grid[i][top]!=1) return -1;
        }
        return top;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // return brute(M,n);
        return optimised(M,n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends