//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact,contact+n);
        
        set<string>st;
        for(int i=0;i<n;i++)
        st.insert(contact[i]);
       vector<vector<string>>ans;
       for(int i=0;i<s.length();i++)
       {
           vector<string>temp;
           string sub=s.substr(0,i+1);
           for(auto it:st)
           {
               if(it.size()<sub.size())
                continue;
                if(it.substr(0,sub.size())==sub)
                temp.push_back(it);
               
           }
           if(temp.size()>0)
           ans.push_back(temp);
           else
           ans.push_back({"0"});
       }
       return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends