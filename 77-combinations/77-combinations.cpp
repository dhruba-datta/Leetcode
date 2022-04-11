class Solution {
public:   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k, 0);
        int itr = 0;

        while(itr > -1){
            temp[itr]++;
            if(temp[itr] > n) itr--;
            else if(itr == k-1) res.push_back(temp);
            else{                
                itr++;
                temp[itr] = temp[itr-1];
            }
        }
        return res;
    }
};