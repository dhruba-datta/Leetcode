class Solution {
public:
int lengthOfLongestSubstring(string s) {
int n = s.size();
vector<int>a(256, -1);
int ans=0, start=-1;
for(int i=0; i<n; i++){
if(a[s[i]]>start)
start = a[s[i]];
a[s[i]]=i;
ans = max(ans, i-start);
}
return ans;
}
};