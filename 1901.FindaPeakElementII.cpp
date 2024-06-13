class Solution {
public:
    int findmax(vector<vector<int>>& mat, int n, int mid) {
        int maxval = -1;
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(mat[i][mid] > maxval) {
                maxval = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int maxi = findmax(mat, n, mid);
            int left = mid - 1 >= 0 ? mat[maxi][mid - 1] : -1;
            int right = mid + 1 <= m - 1 ? mat[maxi][mid + 1] : -1;
            if(mat[maxi][mid] > left && mat[maxi][mid] > right) {
                return {maxi, mid};
            }
            else if(mat[maxi][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
