class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n= intervals.size(), a=0;
        
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);
        
        for(int i=1; i<n; i++){
            if(intervals[i][0]<=ans[a][1]){
                ans[a][0]= min(ans[a][0], intervals[i][0]);
                ans[a][1]= max(ans[a][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                a++;
            }
        }
        
        return ans;
    }
};