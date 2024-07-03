class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (mpp.find(i) == mpp.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
