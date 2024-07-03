class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> final(26, INT_MAX);
        for (int i = 0; i < words.size(); i++) {
            vector<int> cur(26, 0);        
            for (auto c : words[i]) {
                cur[c - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                final[j] = min(final[j], cur[j]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (final[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                final[i]--;
            }
        }
        return ans;
    }
};
