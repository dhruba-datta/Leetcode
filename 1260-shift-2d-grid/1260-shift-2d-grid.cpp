class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> ans(r, vector<int> (c, 0));
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[(i+(j+k)/c)%r][(j+k)%c] = grid[i][j];
            }
        }
        return ans;
    }
};
