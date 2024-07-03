class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr; 
        sort(sortedArr.begin(), sortedArr.end()); 
        unordered_map<int, int> mpp;
        int j = 1;
        for (int i = 0; i < n; ++i) {
            if (mpp.find(sortedArr[i]) == mpp.end()) {
                mpp[sortedArr[i]] = j;
                j++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(mpp[arr[i]]);
        }

        return ans;
    }
};
