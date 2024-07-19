//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/


class Solution {
  public:
    
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        if(n==0)return 0;
        int max_len=0;
        map<int, int>mpp;
        mpp[0]=-1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(mpp.find(sum)!=mpp.end()){
                max_len=max(max_len, i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
        
        
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends