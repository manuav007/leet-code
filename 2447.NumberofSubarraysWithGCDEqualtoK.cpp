class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int currentGCD = nums[i];
            for (int j = i; j < n; j++) {
                int a = currentGCD;
                int b = nums[j];
                while (a > 0 && b > 0) {
                    if (a > b) {
                        a = a % b;
                    } else {
                        b = b % a;
                    }
                }
                currentGCD = a + b; 
                if (currentGCD == k) {
                    ans++;
                }
                if (currentGCD < k) {
                    break; 
                }
            }
        }
        return ans;
    }
};
