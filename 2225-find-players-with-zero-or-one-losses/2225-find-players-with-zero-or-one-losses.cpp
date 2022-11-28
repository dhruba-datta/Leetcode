class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lost_count;
        set<int> participants;
        for(int i=0 ; i<matches.size() ; i++){
            participants.insert(matches[i][0]);
            participants.insert(matches[i][1]);
            lost_count[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto it : participants){
            if(lost_count.find(it) == lost_count.end()){
                ans[0].push_back(it);
            }
            else{
                if(lost_count[it] == 1){
                    ans[1].push_back(it);
                }
            }
        }

        return ans;
    }
};