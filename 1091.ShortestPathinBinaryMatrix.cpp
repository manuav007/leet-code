class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        while (!q.empty()) {
            int currDist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for (auto dir : directions) {
                int crow = r + dir[0];
                int ccol = c + dir[1];
                if (crow >= 0 && crow < n && ccol >= 0 && ccol < m && grid[crow][ccol] == 0 && currDist + 1 < dist[crow][ccol]) {
                    dist[crow][ccol] = currDist + 1;
                    q.push({currDist + 1, {crow, ccol}});
                }
            }
        }
        if(dist[n-1][m-1]!=INT_MAX){
            return dist[n-1][m-1];
        }
        return -1;
    }
};
