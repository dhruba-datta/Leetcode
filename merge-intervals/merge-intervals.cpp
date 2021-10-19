class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        ans.push_back({intervals[0][0],intervals[0][1]});
       
        if(n==1)
            return ans;
        
        int a=0, b=0, i=1;
        while(i<n){
            if(ans[a][1]>=intervals[i][0]){
                ans[a][1]= max(ans[a][1],intervals[i][1]);
                i++;
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
                a++;
            }
        }
        return ans;     
    }
};