class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a;
        long long ans = 1; 
        a.push_back(ans);
        for(int i = 1; i <= rowIndex; i++) {
            ans = ans * (rowIndex - i + 1) / i;
            a.push_back(ans);
        }
        return a;
    }
};
