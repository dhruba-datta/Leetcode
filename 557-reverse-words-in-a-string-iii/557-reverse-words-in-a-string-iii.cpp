class Solution {
public:
    string reverseWords(string s) {
        string ans="", temp="";
        
        for(auto x:s){
            if(x==' '){
                reverse(temp.begin(), temp.end());
                ans = ans + temp + ' ';
                temp = "";
            }
            else{
                temp += x;
            }
        }
        reverse(temp.begin(), temp.end());
        if(s[s.size()-1] != ' ') ans += temp;
        
        return ans;
    }
};