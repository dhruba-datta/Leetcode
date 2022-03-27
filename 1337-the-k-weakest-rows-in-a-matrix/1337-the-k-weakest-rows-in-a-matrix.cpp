class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        vector< pair <int,int> > vect;
        
        int n=mat.size(), m=mat[0].size();
        
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<m; j++){
                if(mat[i][j]==1) count++;
            }
            vect.push_back( make_pair(count,i) );
        }
        sort(vect.begin(), vect.end());
        
        for(int i=0; i<k; i++){
            ans.push_back(vect[i].second);
        }
        return ans;
    }
};