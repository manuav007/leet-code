class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1), cnt(n, 1);
        int maxi=1;
        for(int i=0; i<n; i++){
            for(int pre=0; pre<i; pre++){
                if(nums[pre] < nums[i] && 1+dp[pre]>dp[i]){
                    dp[i] = 1+dp[pre];
                    cnt[i] = cnt[pre];
                }
                else if(nums[pre] < nums[i] && dp[pre]+1 == dp[i]){
                    cnt[i]+=cnt[pre];
                }
            }
            maxi = max(maxi,dp[i]);
            if(i==n-1) break;
        }
        int nos=0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) nos+=cnt[i];
        }
        return nos;
    }
};
