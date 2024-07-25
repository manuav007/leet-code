class Solution {
public:
    bool checkPossible(string& s1, string& s2){
        if(s1.size() != s2.size()+1) return false;
        int first=0, sec=0;
        while(first<s1.size()){
            if(s1[first] == s2[sec]){
                first++;
                sec++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && sec == s2.size()) return true;
        return false;
    }
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n , 1);
        int maxi=1;
        for(int i=0; i<n; i++){
            for(int pre=0; pre<i; pre++){
                if(checkPossible(words[i],words[pre]) && 1+dp[pre]>dp[i]){
                    dp[i] = max(dp[i], 1+dp[pre]);
                }
            }
            maxi = max(maxi,dp[i]);
            if(i==n-1) break;
        }
        return maxi;
    }
};
