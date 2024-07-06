class Solution {
public:
    int arrangeCoins(int n) {
        int low=0;
        int high=n;
        while(low<=high){
            int m=(low+high)/2;
            long long int coin = (long long)m*(m+1)/2;
            if(coin == n) return m;
            else if(coin > n) high=m-1;
            else low = m+1;
        }
        return high;
    }
};
