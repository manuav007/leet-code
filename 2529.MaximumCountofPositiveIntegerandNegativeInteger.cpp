class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0]>0) return nums.size();
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] < 0) {
                l = m + 1;  
            } else {
                h = m - 1;
            }
        }
        int neg = l;
        int pos = nums.size() - neg;  
        for(int i=neg; i<nums.size(); i++){
            if(nums[i] == 0) pos--; 
            else break;
        }
        return max(pos, neg);
    }
};
