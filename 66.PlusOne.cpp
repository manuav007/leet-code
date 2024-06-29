class Solution {
public:
    vector<int> plusOne(std::vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int d = 1;
        for (int i = n - 1; i >= 0; --i) {
            int sum = digits[i] + d;
            ans.insert(ans.begin(),sum % 10);
            d = sum / 10; 
        }

        if (d > 0) {
            ans.insert(ans.begin(), d);
        }
        return ans;
    }
};
