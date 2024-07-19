//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>> &mat,vector<string> &paths,string &path,int r,int c){
        if(r == mat.size()-1 && c == mat[0].size()-1){
            paths.push_back(path);
            return;
        }
        if(r>0 && mat[r-1][c]==1){
            path.push_back('U');
            mat[r][c] = 0;
            solve(mat,paths,path,r-1,c);
            mat[r][c] = 1;
            path.pop_back();
        }
        if(c<mat[0].size()-1 && mat[r][c+1]==1){
            path.push_back('R');
            mat[r][c] = 0;
            solve(mat,paths,path,r,c+1);
            mat[r][c] = 1;
            path.pop_back();
        }
        if(r<mat.size()-1 && mat[r+1][c]==1){
            path.push_back('D');
            mat[r][c] = 0;
            solve(mat,paths,path,r+1,c);
            mat[r][c] = 1;
            path.pop_back();
        }
        if(c>0 && mat[r][c-1]==1){
            path.push_back('L');
            mat[r][c] = 0;
            solve(mat,paths,path,r,c-1);
            mat[r][c] = 1;
            path.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> paths;
        if(mat[0][0]==0){
            return paths;
        }
        string path = "";
        solve(mat,paths,path,0,0);
        return paths;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends