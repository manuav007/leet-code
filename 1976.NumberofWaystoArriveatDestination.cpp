class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> qu;
        qu.push({0, 0});
        long long mod = 1e9 + 7;
        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while(!qu.empty()) {
            long long dis = qu.top().first;
            int node = qu.top().second;
            qu.pop();  

            if (dis > dist[node]) continue;

            for(auto& it : adj[node]) {
                int adjNode = it.first;
                long long edgeWeight = it.second;
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    ways[adjNode] = ways[node];
                    qu.push({dist[adjNode], adjNode});
                } else if(dis + edgeWeight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
