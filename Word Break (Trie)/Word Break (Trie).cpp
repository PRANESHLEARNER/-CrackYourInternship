//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct TrieNode {
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* node = root;
        for (char c : s) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endOfWord = true;
    }

    bool find(string s) {
        TrieNode* node = root;
        for (char c : s) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->endOfWord;
    }
};

class Solution {
public:
    int wordBreak(string A, vector<string>& B) {
        Trie t;
        for (string word : B) {
            t.insert(word);
        }

        int n = A.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = A.substr(j, i - j);
                    if (t.find(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n] ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends