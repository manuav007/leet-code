class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1) {
                qu.push({0, i});
                vis[0][i] = 1;
            }
            if(grid[n-1][i] == 1) {
                qu.push({n-1, i});
                vis[n-1][i] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                qu.push({i, 0}); 
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1) {
                qu.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }
        int delrow[] = {-1, 0, 1, 0}; 
        int delcol[] = {0, 1, 0, -1};
        while(!qu.empty()) {
            int row = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    qu.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int cut = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) cut++;
            }
        }
        return cut;
    }
};
