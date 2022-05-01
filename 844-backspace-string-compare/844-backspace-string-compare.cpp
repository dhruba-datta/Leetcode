class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> mp1, mp2;
        for(auto x:s){
            if(x=='#' && !mp1.empty()) mp1.pop();
            else if(x=='#' && mp1.empty()) continue;
            else mp1.push(x);
        }
        for(auto x:t){
            if(x=='#' && !mp2.empty()) mp2.pop();
            else if(x=='#' && mp2.empty()) continue;
            else mp2.push(x);
        }
        if(mp1 == mp2) return true;
        return false;
    }
};