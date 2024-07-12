class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            int low = 0;
            int high = grid[i].size() - 1;
            if(grid[i][high] > 0) continue;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(grid[i][mid] < 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            count += grid[i].size() - low;
        }
        return count;
    }
};
