class Solution {
public:
    int longestPalindrome(string text1) {
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int n = text1.size();
        int m = text2.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);

        for(int i = 0; i <= m; i++) 
            prev[i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])  
                    curr[j] = 1 + prev[j - 1];
                else 
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }

    int minInsertions(string s) {
        return s.size() - longestPalindrome(s);   
    }
};
