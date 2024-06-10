class Solution {
public:
    int findmax(const vector<int>& piles) {
        int ma = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            ma = max(ma, piles[i]); 
        }
        return ma;
    }
    long long calculatehour(const vector<int>& piles, int mid) {
        long long total = 0; 
        for(int i = 0; i < piles.size(); i++) {
            total += ceil((double)piles[i] / (double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = findmax(piles);
        
        while(low <= high) {
            int mid = (low + high) / 2;
            long long a = calculatehour(piles, mid);
            
            if(a <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
