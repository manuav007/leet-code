class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxs = 0;
        for(int i=0; i<k; i++){
            lsum = lsum+cardPoints[i];
            maxs = lsum;
        }
        int rlen = cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rlen];
            rlen = rlen-1;
            maxs = max(maxs,lsum+rsum);
        }
        return maxs;
    }
};
