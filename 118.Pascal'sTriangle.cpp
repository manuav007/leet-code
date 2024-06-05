class Solution {
public:
    vector<int> generatecol(int n){
        vector<int> ans;
        int a = 1;
        ans.push_back(a);
        for(int i=1; i<n; i++){
            a = a * (n-i);
            a = a/i;
            ans.push_back(a); 
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generatecol(i));
        }
        return ans;
    }
};
