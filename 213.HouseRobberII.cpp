class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return nums[n];
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        int pick = nums[n] + f(nums, n-2, dp); 
        int nopick = 0 + f(nums, n-1, dp); 
        return dp[n] = max(pick, nopick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        vector<int> temp1, temp2;
        
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n-1) temp2.push_back(nums[i]);
        }
        
        return max(f(temp1, n-2, dp1), f(temp2, n-2, dp2));
    }
};
