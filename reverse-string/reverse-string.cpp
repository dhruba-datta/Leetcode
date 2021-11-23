class Solution {
public:
    
    void reverseString(vector<char>& s) {
        int n= s.size();
        for(int i=n-1; i>=0; i--){
            s.push_back(s[i]);
        }
        s.erase(s.begin(), s.begin()+n);
        return;
    }
};