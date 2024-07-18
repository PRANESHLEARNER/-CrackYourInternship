//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL) return head;
        vector<int> st;
        Node* num=head;
        while(num!=NULL)
        {
            st.push_back(num->data);
            num=num->next;
        }
        vector<int> out;
        for(int i=0;i<st.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<st.size();j++)
            {
                if(st[j]>st[i]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                out.push_back(st[i]);
            }
        }
        Node* result=new Node(out[0]);
        Node* dummy=result;
        for(int i=1;i<out.size();i++)
        {
            dummy->next=new Node(out[i]);
            dummy=dummy->next;
        }
        return result;
    }
    
};
   
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends