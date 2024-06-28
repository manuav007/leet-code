class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> qu;
        qu.push({0, {src, 0}});  
        vector<int> dist(n, 1e9);
        dist[src] = 0; 
        while(!qu.empty()) {
            auto a = qu.front();
            qu.pop();
            int step = a.first;
            int node = a.second.first;
            int cost = a.second.second;
            if(step > k) continue;
            for(auto it : adj[node]) {
                int adjnode = it.first;
                int adw = it.second;  
                if(adw + cost < dist[adjnode]) { 
                    dist[adjnode] = adw + cost;
                    qu.push({step + 1, {adjnode, cost + adw}}); 
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
