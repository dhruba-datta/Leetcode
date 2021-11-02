class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int ans=INT_MIN;
        int sum=0;
        int n= a.size();
        for(int i=0; i<k; i++){
            sum += a[i];
        }
        ans = sum;
        for(int i=0; i<k; i++){
            sum -= a[k-i-1];
            sum += a[n-i-1];
            ans = max(ans, sum);
        }
        return ans;
        
    }
};