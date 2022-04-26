class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        set<pair<int, int>> s;
        vector<vector<pair<int, int>>> graph(points.size());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                graph[i].push_back({j, getDistance(points[i], points[j])});
                graph[j].push_back({i, getDistance(points[i], points[j])});
                
            }
        }
        
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        
        s.insert({0, 0});
        dist[0] = 0;
        int ans = 0;
        while(!s.empty()) {
            
            pair<int, int> p = *s.begin();
            s.erase(p);
            if(visited[p.second]) {
                continue;
            }
            
            visited[p.second] = true;
            
            int u = p.second;
            ans += p.first;
            for(auto nbr: graph[u]) {
                if(!visited[nbr.first] && dist[nbr.first] > nbr.second) {
                    s.erase({dist[nbr.first], nbr.first});
                    dist[nbr.first] = nbr.second;
                    s.insert({nbr.second, nbr.first});
                }    
            }
        }
        
        return ans;
    }
    
    int getDistance(vector<int>& v1, vector<int>& v2) {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
};