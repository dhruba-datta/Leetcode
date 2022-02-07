class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        int n = s.size(), i=0;
        char ans;
        
        for(auto x:t){
            v[x-'a'] += 1;
        }
        for(auto x:s){
            v[x-'a'] -= 1;
        }
        
        for(int i=0; i<26; i++){
            if(v[i] != 0)
                ans = i + 'a';
        }
        
        return ans;
    }
};