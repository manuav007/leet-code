class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0), cur(m, 0);

        // Initialize the first row
        for(int j = 0; j < m; j++) 
            prev[j] = matrix[0][j];

        // Iterate through each row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                
                int ld = matrix[i][j];
                if (j > 0) ld += prev[j - 1];
                else ld += 1e8;
                
                int rd = matrix[i][j];
                if (j < m - 1) rd += prev[j + 1];
                else rd += 1e8;

                cur[j] = min(up, min(ld, rd));
            }
            prev = cur;
        }
        int mi = prev[0];
        for(int j = 1; j < m; j++) {
            mi = min(mi, prev[j]);
        }

        return mi;
    }
};
