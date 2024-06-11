class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        for(int num : arr1) {
            countMap[num]++;
        }
        vector<int> result;
        for(int num : arr2) {
            while(countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;
            }
        }
        vector<int> remaining;
        for(auto& entry : countMap) {
            while(entry.second > 0) {
                remaining.push_back(entry.first);
                entry.second--;
            }
        }
        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());
        return result;
    }
};
