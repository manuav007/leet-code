class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qu;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    qu.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!qu.empty()){
            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int dis = qu.front().second;
            qu.pop();
            dist[row][col] = dis;
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    qu.push({{nrow,ncol}, dis+1});
                }
            }
        }
        return dist;
    }
};
