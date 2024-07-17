//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void swap(char &a,char &b){
        char temp=a;
        a=b;
        b=temp;
    }
    
    void solve(string &str,string &ans,int &k,int index){
        
        //updating ans
        
        ans=max(ans,str);
        
        if(k==0){//base condition
            return;
        }
        
        
        //loops
        
        for(int i=index;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[j]>str[i]){ // most important condition
                    
                swap(str[i],str[j]);
                k--;
                
                solve(str,ans,k,i); //recursive call
                
                //backtracking
                k++;
                swap(str[i],str[j]);
                }
            }
        }
    
        
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans="";
       solve(str,ans,k,0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends