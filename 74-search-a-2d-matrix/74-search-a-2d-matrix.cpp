class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int target) {
        int n = mt.size();
        
        for(int i=0; i<n; i++){
            if(binary_search(mt[i].begin(), mt[i].end(), target) ==  true) 
                return true;
        }
        
        return false;
    }
};