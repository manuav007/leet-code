class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<long long> cur(m+1, 0), prev(m+1, 0);
        cur[0] = prev[0] = 1; // One way to match an empty t
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == t[j-1]) {
                    cur[j] = prev[j-1] + prev[j];
                } else {
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }
        
        return static_cast<int>(prev[m]);
    }
};
