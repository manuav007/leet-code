class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count=-1;
        for(int i=0; i<nums.size(); i++){
            if (i > k) {
                mpp.erase(nums[i - k - 1]);
            }
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                return true;
            }
            count++;
        }
        return false;
    }
};
