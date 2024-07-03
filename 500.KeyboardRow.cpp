class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> m;
        string row1 = "qwertyuiop";
        for (char c : row1) m[c] = 1;
        string row2 = "asdfghjkl";
        for (char c : row2) m[c] = 2;
        string row3 = "zxcvbnm";
        for (char c : row3) m[c] = 3;
        for (const auto& word : words) {
            if (word.empty()) continue; 
            bool flag = true;
            int row = m[tolower(word[0])];
            for (char ch : word) {
                if (m[tolower(ch)] != row) {
                    flag = false;
                    break;
                }
            }   
            if (flag) {
                ans.push_back(word);
            }
        }      
        return ans;
    }
};
