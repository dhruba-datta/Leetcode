class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans, res;
        int count=0;
        int n=s.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                count++;
                st.push(i);
            }
            else if(s[i]==')'){
                if(count>0){
                    count--;
                    st.pop();
                }
                else
                    st.push(i);
            }
            
        }
        n = st.size();
        
        while(n!=0){
            int i= st.top();
            s.erase(i,1);
            st.pop();
            n--;
        }
        
        return s;
    }
};