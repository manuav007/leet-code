class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead(n + 1, 0), curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prevind = ind - 1; prevind >= -1; prevind--) {
                int len = ahead[prevind + 1];
                if (prevind == -1 || nums[ind] > nums[prevind]) {
                    len = max(len, 1 + ahead[ind + 1]);
                }
                curr[prevind + 1] = len;
            }
            ahead = curr;
        }
        return ahead[0];
    }
};
