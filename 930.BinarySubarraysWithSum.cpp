class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal) - func(nums,goal-1);
    }
    int func(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum = sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
};
