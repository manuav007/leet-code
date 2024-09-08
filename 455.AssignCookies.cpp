class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int r = 0, l = 0;
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (r < n && l < m) {
            if (s[l] >= g[r]) {
                r++;  
            }
            l++;  
        }
        return r; 
    }
};
