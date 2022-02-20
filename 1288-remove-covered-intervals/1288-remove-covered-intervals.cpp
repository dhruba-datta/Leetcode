class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), count=0, l=-1, r=-1;
        sort(intervals.begin(), intervals.end());
        
        
        for(int i=0; i<n; i++){
            if(intervals[i][0] > l && intervals[i][1] > r){
                l = intervals[i][0];
                count++;
            }
            r = max(r, intervals[i][1]);
        }
        return count;
    }
};