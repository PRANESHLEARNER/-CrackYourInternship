//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool isPalindrome(string s) {
        int begin = 0, end = s.length()-1;
        
        while(begin < end) {
            if(s[begin] != s[end])
                return false;
                
            begin++, end--;
        }
        
        return true;
    }
    
    void palindromePerm(string s, int index, vector<string> temp, vector<vector<string>> &result) {
        if(index == s.length()) {
            result.push_back(temp);
            return;
        }   
        
        string curr;
        for(int i=index; i<s.length(); i++) {
            curr.push_back(s[i]);
            
            if(isPalindrome(curr)) {
                temp.push_back(curr);
                
                palindromePerm(s, i+1, temp, result);
                
                temp.pop_back();
            }
        }
    }
    
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> temp;
        vector<vector<string>> result;
        int index = 0;
        
        palindromePerm(S, index, temp, result);
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends