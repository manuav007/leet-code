class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mi = prices[0];
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i]-mi);
            mi = min(mi, prices[i]); 
        }
        return profit;
    }
};
