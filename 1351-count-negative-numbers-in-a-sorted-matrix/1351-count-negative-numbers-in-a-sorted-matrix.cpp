class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        for(int i=0; i<grid.size(); i++){
            count += upper_bound(grid[i].rbegin(), grid[i].rend(), -1) - grid[i].rbegin();
        }
        
        return count;
    }
};