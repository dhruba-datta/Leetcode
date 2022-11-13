class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans, word;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(s[i] == ' ' && word.size() != 0){
                st.push(word); 
                word = "";
            }
            else if(s[i] == ' ' && word.size() == 0){
                continue;
            }
            else
                word += s[i];
        }
        if(word.size() != 0){
            st.push(word); 
            word = "";
        }
            
        while(!st.empty()){
            string temp = st.top();
            ans += temp + ' ';
            st.pop();
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};