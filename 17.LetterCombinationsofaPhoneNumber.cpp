class Solution {
public:
    void solve(int index, string digits, vector<string>& ans, string mpp[], string out) {
        if (index >= digits.length()) {
            ans.push_back(out);
            return;
        }
        int num = digits[index] - '0';
        string val = mpp[num];
        for (int i = 0; i < val.length(); i++) {
            out.push_back(val[i]);
            solve(index + 1, digits, ans, mpp, out);
            out.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans; 
        int index = 0;
        string out = "";
        string mpp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(index, digits, ans, mpp, out);
        return ans;
    }
};
