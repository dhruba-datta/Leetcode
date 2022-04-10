class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                st.push(y);
                st.push(x);
                st.push(x+y);
            }
            
            else if(ops[i] == "C"){
                st.pop();
            }
            
            else if(ops[i] == "D"){
                st.push(2*st.top());
            }
            else{
                int x = stoi(ops[i]);
                st.push(x);
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