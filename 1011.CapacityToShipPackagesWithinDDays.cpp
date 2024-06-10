class Solution {
public:
    int days(vector<int>& weights, int maxLoad) {
        int days = 1;  
        int currentLoad = 0; 
        for(int i = 0; i < weights.size(); i++) {
            if(currentLoad + weights[i] > maxLoad) {
                currentLoad = weights[i];
                days++;
            } else {
                currentLoad += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high) {
            int mid = (low + high) / 2;
            if(days(weights, mid) <= D) {\
                high = mid - 1;
            } else {\
                low = mid + 1;
            }
        }
        return low;
    }
};
