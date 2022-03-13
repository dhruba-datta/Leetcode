class Solution {
public:
    bool isValid(string s) {
        bool ans = false;
        int n = s.size();
        stack<char> st;
        
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            
            else if(!st.empty()){
                if(s[i] == ')' && st.top() == '(')
                    st.pop();
                else if(s[i] == '}' && st.top() == '{')
                    st.pop();
                else if(s[i] == ']' && st.top() == '[')
                    st.pop();
                else 
                    return false;
            }
            
            else 
                return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};