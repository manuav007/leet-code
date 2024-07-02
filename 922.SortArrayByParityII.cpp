class Solution {
public:
    vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int even = 0;
        int odd = 1;
        int i = 0;
        
        while (i < n) {
            if (nums[i] % 2 == 0) {
                ans[even] = nums[i];
                even += 2;
            } else {
                ans[odd] = nums[i];
                odd += 2;
            }
            i++;
        }
        return ans;
    }
};
