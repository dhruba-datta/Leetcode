class Solution {
public:
    int countSubstrings(string s) {
	int n = size(s), cnt = n; 
	for(int i = 1, l = 0, r = 2; i < n; i++, l = i - 1, r = i + 1)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;   
	for(int i = 1, l = 0, r = 1; i < n; i++, l = i - 1, r = i)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;            
	return cnt;
}
};