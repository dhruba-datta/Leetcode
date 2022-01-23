class Solution {
public:
    int romanToInt(string s) {
        int n= s.size(), ans=0, i=0, num;
        unordered_map<char, int> mp;
        mp['I']=1 ;mp['V']=5 ;mp['X']=10 ;mp['L']=50 ;mp['C']=100 ;mp['D']=500 ;mp['M']=1000 ;
               
        while(i<n){
            if(i==n-1 || (mp[s[i]]>=mp[s[i+1]])){
                num = mp[s[i]];
                i++;
            }
            else{
                num = mp[s[i+1]] - mp[s[i]];
                i += 2;
            }         
            ans += num;
        }
        
        return ans;
    }
};
