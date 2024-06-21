class Solution {
public:
    void sub(vector<int>& nums, vector<vector<int>>& ans, vector<int> output, int index = 0){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        sub(nums,ans,output,index+1);
        output.push_back(nums[index]);
        sub(nums,ans,output,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        sub(nums,ans,output,index);
        return ans;
    }
};
