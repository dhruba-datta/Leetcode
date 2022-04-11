class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        help(1, temp, ans, n, k);
        return ans;
    }
    
    void help(int num, vector<int> &temp, vector<vector<int>> &ans, int n, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=num; i<=n; i++){
            temp.push_back(i);
            help(i+1, temp, ans, n, k);
            temp.pop_back();   
        }
    }
};