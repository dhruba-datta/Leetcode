class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    
    vector<vector<string>> partition(string s) {
        help(0, s);
        return ans;
    }
    
    void help(int idx, string s){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<s.size(); i++){
            if(pal(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                help(i+1, s);
                temp.pop_back();
            }
        }
    }
    
    bool pal(string s, int start, int end){
        while(start <= end) if(s[start++] != s[end--]) return false;
        return true;
    }
};
/*
    void help(int index, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                help(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
*/