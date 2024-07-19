//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    Node* findLCA(Node* &root, int a, int b){
        if(root==NULL||root->data==a||root->data==b){
            return root;
        }
        auto left = findLCA(root->left, a, b);
        auto right = findLCA(root->right, a , b);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
    int helper(Node* &root,int distance, int a){
        if(root==NULL) return -1;
        if(root->data == a){
            return distance;
        }
        auto left = helper(root->left, distance+1, a);
        if(left!=-1){
            return left;
        }
        else{
            return helper(root->right, distance+1, a); 
        }
    }
    int findDist(Node* root, int a, int b) {
        
        // int roota = 0;
        // int rootb = 0;
        // int rootlca = 0;
        // Node* newlca = findLCA(root, a , b);
        // int newdata = newlca->data;
        // helper(root, roota,a);
        // helper(root, rootb, b);
        // helper(root, rootlca, newdata);
        // return ((roota+rootb)-(2*rootlca));
        
        // Your code heretiin
        Node* lca = findLCA(root, a, b);
        int distance1 = helper(lca,0, a);
        int distance2 =helper(lca, 0, b);
        return (distance1+distance2);
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends