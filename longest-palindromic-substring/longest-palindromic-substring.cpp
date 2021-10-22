class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st=0;
        int l=0, r, mx=0;
        if(n<2) return s;
        
        
        for(int i=0; i<n-1; i++){
            l=i; r=i+1;
             while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--; r++;
                }
                else
                    break;
            }
            int len= r-l-1;
            if(len>mx){
                mx= len;
                st= l+1;
            }
        }
        for(int i=0; i<n-1; i++){
            l=i; r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--; r++;
                }
                else
                    break;
            }
            int len= r-l-1;
            if(len>mx){
                mx= len;
                st= l+1;
            }
        }
        
        return s.substr(st, mx);
    }
};