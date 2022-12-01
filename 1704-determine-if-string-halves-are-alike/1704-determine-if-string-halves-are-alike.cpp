class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int> m;
        int n = s.length();

        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;

        int c1 = 0;
        int c2 = 0;

        for(int i = 0; i < n/2;i++){
            if(m[tolower(s[i])]){
               c1++;
            }
        }

        for(int j = n/2;j < n;j++){
            if(m[tolower(s[j])]){
                c2++;
            }
        }

        return c1 == c2;
    }
};