class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int x=0, y=0;
        
        // for string s
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                x--;
                x = max(0, x);
            }
            else{
                s[x] = s[i];
                x++;
            }
        }
        // for string t
        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                y--;
                y = max(0, y);
            }
            else{
                t[y] = t[i];
                y++;
            }
        }
        
        if(x != y) return false;
        else{
            for(int i=0; i<x; i++){
                if(s[i] != t[i]) return false;
            }
            return true;
        }
    }
};