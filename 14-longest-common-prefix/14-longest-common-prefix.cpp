class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mn = INT_MAX, count = 0;
        string str;
        
        for(int i=0; i<n; i++){
            if(mn > strs[i].size()){
                mn = strs[i].size();
                str = strs[i];
            }
        }
        
        for(int i=0; i<mn; i++){
            for(int j=0; j<n; j++){
                if(strs[j][i] != str[i])
                    return str.substr(0, count);
            }
            count++;
        }
        return str.substr(0,count);        
    }
};