class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        vector<int> result;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                int left = mid;
                while (left >= 0 && nums[left] == target) {
                    left--;
                }
                int right = mid;
                while (right < nums.size() && nums[right] == target) {
                    right++;
                }
                for (int i = left + 1; i < right; i++) {
                    result.push_back(i);
                }
                return result;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result; 
    }
};
