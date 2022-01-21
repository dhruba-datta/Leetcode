class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        
        priority_queue < pair<int, int> > q;
        
        for(int i=0; i<n; i++){
            
            while((!q.empty()) && points[i][0]-q.top().second>k) q.pop();
                
            if(!q.empty())
                ans = max(ans, (q.top().first + points[i][0] + points[i][1]));
            
            q.push({points[i][1] - points[i][0], points[i][0]});
        }
        
        return ans;
    }
};