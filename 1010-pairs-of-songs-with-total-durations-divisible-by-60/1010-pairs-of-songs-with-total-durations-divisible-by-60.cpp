class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n= time.size();
        vector<int>ans(60);
        
        for(auto x:time)
            ans[x%60] += 1;
        
        int count=0;
        count += ((ans[0]-1)*ans[0])/2;
        count += ((ans[30]-1)*ans[30])/2;
        
        for(int i=1; i<30; i++)
            count += ans[i]*ans[60-i];
        
        return count;
    }
};