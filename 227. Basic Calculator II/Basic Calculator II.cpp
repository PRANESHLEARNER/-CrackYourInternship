class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        char pre_op = '+';
        for(int i=0; i<n; i++){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                int num = 0;
                while(i<n && isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(pre_op == '+') st.push(num);
                else if(pre_op == '-') st.push(-num);
                else{
                    int top;
                    if(pre_op == '*'){
                        top = st.top()*num;
                    }else{
                        top = st.top()/num;
                    }
                    st.pop();
                    st.push(top);
                }
            }else{
                pre_op = s[i];
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};