class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1, count1=0, count2=0;
        while(i<j){
            if(s[i] != s[j])
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            i++; j--;
        }
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) 
                return false;
            i++; j--;
        }
        return true;
    }
    
};