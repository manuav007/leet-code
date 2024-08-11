class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashset[256];
        fill_n(hashset, 256, -1);
        int l=0, r=0, maxlen=0;
        int n=s.size();
        while(r<n){
            if(hashset[s[r]] != -1){
                if(hashset[s[r]] >= l){
                    l=hashset[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            hashset[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
