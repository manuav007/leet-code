class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n + 1, -1);
        return climbStairs(n, vec);
    }

    int climbStairs(int n, vector<int>& vec) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (vec[n] != -1) {
            return vec[n];
        }
        return vec[n] = climbStairs(n - 1, vec) + climbStairs(n - 2, vec);
    }
};
