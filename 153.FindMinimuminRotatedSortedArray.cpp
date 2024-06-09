class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int m = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[high]){
                m = min(m, nums[low]);
                break;
            }
            if(nums[mid] >= nums[low]){
                m = min(m, nums[low]);
                low = mid+1;
            }
            else{
                high = mid-1;
                m = min(m, nums[mid]);
            }
        }
        return m;
    }
};
