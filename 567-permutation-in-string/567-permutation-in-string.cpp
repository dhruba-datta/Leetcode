class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), j=0;
        vector<int> a(26, 0), b(26, 0);
        
        if(n>m)
            return false;
        
        else if(n<m){
            for(auto x:s1)
                a[x-'a']++;
            for(int i=0; i<n; i++)
                b[s2[i]-'a']++;
            
            if(a == b) return true;
            
            for(int i=n; i<m; i++){
                b[s2[i]-'a']++;
                b[s2[j]-'a']--;
                if(a==b) return true;
                j++;
            }         
        }
        
        else{
            for(auto x:s1)
                a[x-'a']++;
            for(auto x:s2)
                b[x-'a']++;
            if(a == b) return true;
        }
        return false;
    }
};