class Solution {
public:
    int dp[205][20005];

    bool f(int i, vector<int>& nums, int tar) {
        if (tar == 0) return true;
        if (i == 0) return nums[0] == tar;
        if (dp[i][tar] != -1) return dp[i][tar];
        
        bool notTake = f(i - 1, nums, tar);
        bool take = false;
        if (nums[i] <= tar) {
            take = f(i - 1, nums, tar - nums[i]);
        }

        return dp[i][tar] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int tar = 0;
        for (int i = 0; i < nums.size(); i++) {
            tar += nums[i];
        }

        if (tar % 2 == 1) return false;

        tar = tar / 2;

        memset(dp, -1, sizeof(dp));
        return f(nums.size() - 1, nums, tar);
    }
};
