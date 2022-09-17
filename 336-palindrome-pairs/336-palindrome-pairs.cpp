class Solution {
public:
    bool pal(int s, int e, string st){
        while(s < e){
            if(st[s] != st[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<vector<int>> v;
        unordered_map<string,int>mp;
        int n = words.size();
        for(int i = 0; i < n; i++){
            mp[words[i]] = i;
        }
        for(int i = 0; i < n; i++){
            string temp = "";
            int n1 = words[i].size();
            if(mp.find(temp) != mp.end() && mp[temp] != i){
                if(pal(0,n1-1,words[i])){
                    vector<int>t;
                    t.push_back(i);
                    t.push_back(mp[temp]);
                    v.insert(t);
                    v.insert({mp[temp],i});
                }              
            }
            for(int j = 0; j < n1; j++){
                temp = words[i][j] + temp;
                if(mp.find(temp) != mp.end() && mp[temp] != i){
                    if(pal(j+1,n1-1,words[i])){
                        vector<int>t;
                        t.push_back(i);
                        t.push_back(mp[temp]);
                        v.insert(t);
                    }
                }
            }
            for(int j = 0; j < 26; j++){
                char c = 'a' + j;
                string temp1 = c + temp;
                if(mp.find(temp1) != mp.end() && mp[temp1] != i){
                    vector<int>t;
                    t.push_back(i);
                    t.push_back(mp[temp1]);
                    v.insert(t);
                }
            }
            temp = "";
            for(int j = n1-1; j >= 0; j--){
                temp += words[i][j];
                if(mp.find(temp) != mp.end() && mp[temp] != i){
                    if(pal(0,j-1,words[i])){
                        vector<int>t;
                        t.push_back(mp[temp]);
                        t.push_back(i);
                        v.insert(t);
                    }
                }
            }            
        }
        vector<vector<int>>res(v.begin(),v.end());
        return res;
    }
};