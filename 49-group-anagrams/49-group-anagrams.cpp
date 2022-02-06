class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>>ans;
        
        int i=0;
        while(i<n){
            string a = strs[i];
            sort(a.begin(), a.end());
            mp[a].push_back(strs[i]);
            i++;
        }
        for(auto i=mp.begin(); i!= mp.end(); i++){
            ans.push_back(i->second);
        }
        return ans;
        
    }
};