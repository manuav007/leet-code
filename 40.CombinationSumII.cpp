class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int> da, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(da);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            da.push_back(candidates[i]);
            solve(i+1,ans,da,candidates,target-candidates[i]);
            da.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> da;
        solve(0,ans,da,candidates,target);
        return ans;
    }
};
