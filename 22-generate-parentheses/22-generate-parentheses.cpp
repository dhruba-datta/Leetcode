class Solution {
public:
    vector<string>ans;
    vector<string>generateParenthesis(int n) {
        help("",n,n);
        return ans;
    }
    void help(string s, int open, int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open > 0) help(s+"(", open-1, close);
        if(open < close) help(s+")", open, close-1);
    }
};