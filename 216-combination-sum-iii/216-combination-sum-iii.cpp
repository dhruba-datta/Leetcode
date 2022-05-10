class Solution {
private:
    vector<vector<int>> ans;
public:
    /*
        BACKTRACKING BASED SOLUTION:
        ===========================        
    */
    
    
    int sum(const vector<int>& combo) {
        int temp = 0;
        for (int x : combo)
            temp += x;
        return temp;
    }
    
    void helper(vector<int>& combo, int k, int n, int num) {
        if (!k) {
            if (sum(combo) == n)
                ans.push_back(combo);
            return;
        }
        
        if (num > 9) return;
        
        combo.push_back(num);
        helper(combo, k - 1, n, num + 1);
        combo.pop_back();
        helper(combo, k, n, num + 1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combo;
        helper(combo, k, n, 1);
        return ans;
    }
};