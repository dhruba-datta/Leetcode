class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        for(auto x:nums) mp[ x]++;
        
        help(0, n);
        return ans;
    }
    
    void help(int index, int n){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        for(auto k:mp){
            int key = k.first;
            int value = k.second;
            
            if(value == 0) continue;
            
            temp.push_back(key);
            mp[key]--;
            
            help(index+1, n);
            
            temp.pop_back();
            mp[key]++;
        }
    
    }
   
};