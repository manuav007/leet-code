class Solution {
public:
    void solve(int ind, vector<int> ds, vector<vector<int>>& ans, vector<int> candidates, int target) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (ind == candidates.size() || target < 0) {
            return;
        }
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            solve(ind, ds, ans, candidates, target - candidates[ind]);
            ds.pop_back();
        }
        solve(ind + 1, ds, ans, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, ds, ans, candidates, target);
        return ans;
    }
};
