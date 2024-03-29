class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<map<char, int>, vector<string>> mp;
        vector<vector<string>>ans;
        
        int i=0;
        //n
        while(i<n){
            map<char, int> a;
            //logn
            for(int j=0; j<strs[i].size(); j++)
                a[strs[i][j]]++;
            mp[a].push_back(strs[i]);
            i++;
        }
        //n
        for(auto i=mp.begin(); i!= mp.end(); i++){
            ans.push_back(i->second);
        }
        return ans;
        
    }
};