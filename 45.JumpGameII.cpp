class Solution {
public:
    int jump(vector<int>& nums) {
        int jum = 0, l = 0, r = 0;
        while (r < nums.size() - 1) { 
            int far = 0;
            for (int i = l; i <= r; i++) { 
                far = max(far, i + nums[i]);
            }
            l = r + 1;
            r = far;
            jum = jum + 1;
        }
        return jum;
    }
};
