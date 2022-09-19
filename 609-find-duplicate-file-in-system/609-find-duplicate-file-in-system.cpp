class Solution {
    
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<paths.size();i++){
            string path;
            for(int j=0;j<paths[i].size();j++){
                if(paths[i][j] == '('){
                    j++;
                    string s ;
                    while(paths[i][j]!=')'){
                       s.push_back(paths[i][j]);
                        j++;
                    }
                    mp[s].push_back(path);
                    while(path[path.size()-1]!='/')path.pop_back();
                    path.pop_back();
                    j++;
                }
                if(paths[i][j]==' '){
                    path.push_back('/');
                }
                else{
                    path.push_back(paths[i][j]);
                }
            }
        }
        for(auto x:mp){
            if(x.second.size()>1){
                vector<string>v;
                for(auto str: x.second){
                    v.push_back(str);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};