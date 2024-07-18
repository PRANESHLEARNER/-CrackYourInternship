//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int perform(int a, char ch, int b){
        if (ch=='+')
            return a+b;
        if (ch=='-')
            return b-a;
        if (ch=='*')
            return a*b;
        if (ch=='/')
            return b/a;
        
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for (int i=0;i<S.length();i++){
            char ch= S[i];
            if (isdigit(ch)) {
            st.push(ch - '0');  // Convert char to int
            } else if (ch=='*'||ch=='+'||ch=='-'||ch=='/'){
                int a= st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                int ans=perform(a,ch,b);
                st.push(ans);
            }
            
        }
        return st.top();
    }
    
    
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends