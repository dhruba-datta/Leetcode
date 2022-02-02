class Solution { 
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26, 0), phash(26, 0);
        vector<int> ans;
        int n = s.size(), m = p.size();
        if(m > n) return ans;
        
        int l=0, r=0;
        
        while(r < m){
            shash[s[r]-'a'] += 1;
            phash[p[r]-'a'] += 1;
            r++;
        }
        r -= 1;
        while(r < n){
            if(shash == phash) ans.push_back(l);
            r += 1;
            if(r != n){
                shash[s[r]-'a'] += 1;
                shash[s[l]-'a'] -= 1;
            }
            l++;
        }       
        return ans;
    }
};