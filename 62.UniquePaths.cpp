class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1);
        double rec = 1;
        for (int i = 1; i <= r; i++) {
            rec *= (N - r + i) / (double)i;
        }
        return (int)(rec + 0.5); // Adding 0.5 to handle rounding issues
    }
};
