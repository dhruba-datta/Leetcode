class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto x:s)
            mp[x] = -1;
        
        int i=0, start=-1, ans=0;
        for(int i=0; i<n; i++){
            if(mp[s[i]] > start)
                start = mp[s[i]];
            mp[s[i]] = i;
            ans = max(ans, i-start);
        }
        return ans;
    }
};