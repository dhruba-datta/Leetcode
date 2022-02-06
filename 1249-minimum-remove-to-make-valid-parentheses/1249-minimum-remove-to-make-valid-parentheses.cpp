class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        int i=0, count=0;
        while(i<n){
            if(s[i] == '('){
                count++;
                st.push(i);
            }
            else if(s[i] == ')'){
                if(count > 0){
                    count--;
                    st.pop();
                }
                else
                    st.push(i);
            }
            i++;
        }
        int m = st.size();
        while(m--){
            int temp= st.top();
            s.erase(temp,1);
            st.pop();
        }
        return s;
    }
};