class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int sum1 = 0;
        int sum2 = 0;
        vector<int> ans;
        for (int i = 0; i < aliceSizes.size(); i++) {
            sum1 += aliceSizes[i];
        }
        
        for (int i = 0; i < bobSizes.size(); i++) {
            sum2 += bobSizes[i];
        }
        
        int diff = (sum1 - sum2) / 2;
        
        for (int i = 0; i < bobSizes.size(); i++) {
            int start = 0;
            int end = aliceSizes.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (aliceSizes[mid] == bobSizes[i] + diff) {
                    return {aliceSizes[mid], bobSizes[i]};
                } else if (aliceSizes[mid] < bobSizes[i] + diff) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return {};
    }
};
