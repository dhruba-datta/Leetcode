class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int count = 0, ans = 0;
        stack<int> st;
        
        for(auto x:s){
            if(x == '('){
                st.push(-1);
            }
            else if(x == ')' && st.top() == -1){
                st.pop();
                st.push(1);
            }
            else if(x == ')' && st.top() != -1){
                while(st.top() != -1){
                    count += st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*count);
                count = 0;
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};