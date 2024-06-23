class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> dp;
        solve(0,ans,dp,s);
        return ans;
    }
    void solve(int index,  vector<vector<string>>& ans, vector<string> dp, string s){
        if(index == s.size()){
            ans.push_back(dp);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(ispala(s,index,i)){
                dp.push_back(s.substr(index, i-index+1));
                solve(i+1, ans, dp, s);
                dp.pop_back();
            }
        }
    }
    bool ispala(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};
