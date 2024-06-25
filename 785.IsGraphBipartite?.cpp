class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 0; // Initial coloring

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (auto m : graph[current]) {
                if (visited[m] == -1) { // If not yet visited
                    visited[m] = !visited[current]; // Color with opposite color
                    q.push(m);
                } else if (visited[m] == visited[current]) { // If same color as current
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v, -1); // -1 means unvisited

        for (int i = 0; i < v; i++) {
            if (visited[i] == -1 && !graph[i].empty()) {
                if (!bfs(i, graph, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};
