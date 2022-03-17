class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int count = 0;
        
        for(auto x:s){
            if(x == '('){
                st.push(count);
                count = 0;
            }
            else{
                count = st.top() + max(1, 2*count);
                st.pop();
            }
        }
        return count;
    }
};