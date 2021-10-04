class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> word;
        fun(0, s, word, ans);
        return ans;
    }
    
    void fun(int idx, string s, vector<string> &word, vector<vector<string>> &ans){
        int n= s.size();
        if(idx == n){
            ans.push_back(word);
            return;
        }
        for(int i= idx; i<n; i++){
            if(validPalindrome(s, idx, i)){
                word.push_back(s.substr(idx, i-idx+1));
                fun(i+1, s, word, ans);
                word.pop_back();
            }
        }
        
    }
    
    bool validPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};