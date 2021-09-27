class Solution {
public:
    string reverseWords(string s) {
        string ans, word="";
        stack<string> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ' && word.size()!=0){
                st.push(word);
                word = "";
            }
            else if(s[i]==' ' && word.size()==0)
                continue;
            else
                word += s[i];
        }
        if(word.size()!=0){
            st.push(word);
            word = "";
        }
        int n= st.size();
        for(int i=0; i<n-1; i++){
            ans += st.top() + ' ';
            st.pop();
        }
        ans += st.top();
        st.pop();
        
        return ans;
    }
};