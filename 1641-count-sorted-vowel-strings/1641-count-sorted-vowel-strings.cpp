class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> a(5, 1);
        int ans = 0;
        
        while(--n){
            for(int i=3; i>=0; i--){
                a[i] += a[i+1];
            }
        }
        
        for(auto x:a){
            ans += x;
        }
        
        return ans;
    }
};