class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        image[sr][sc] = newColor;
        int d1[] = {-1, 0, 1, 0};
        int d2[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int newRow = sr + d1[i];
            int newCol = sc + d2[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                image[newRow][newCol] == originalColor && image[newRow][newCol] != newColor) {
                dfs(image, newRow, newCol, newColor, originalColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor != newColor) {
            dfs(image, sr, sc, newColor, originalColor);
        }
        return image;
    }
};
