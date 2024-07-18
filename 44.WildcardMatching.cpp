class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false), cur(m + 1, false);
        prev[0] = true; 
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            cur[0] = false; 
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    cur[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1];
                } else {
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};
