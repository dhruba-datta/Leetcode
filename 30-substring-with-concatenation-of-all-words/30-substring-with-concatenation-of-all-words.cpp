class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length(), size = words.size(), n = s.size();
        vector<int> ans;
        unordered_map<string, int> mp;
        
        if(len*size > n)
            return ans;
        
        for(auto x:words)
            mp[x]++;
        
        for(int i = 0; i <= n-(len*size); i++){
            unordered_map<string, int> m;
            
            for(int j = i; j < i+(len*size); j += len){
                string current = s.substr(j, len);
                
                if(mp.find(current) == mp.end())
                    break;
                
                m[current]++;
                
                if(m[current] > mp[current])
                    break;
            }
            if(mp == m)
                ans.push_back(i);
        }
        
        return ans;
    }
};