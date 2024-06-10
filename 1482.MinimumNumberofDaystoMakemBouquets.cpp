class Solution {
public:
    bool totaldays(vector<int>& bloomDay, int m, int k, int day){
        int count = 0;
        int total = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                total = total + (count/k);
                count = 0;
            }
        }
        total = total + (count/k);
        return total >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()){
            return -1;
        }
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        while(low <= high){
            int mid = (low+high)/2;
            if(totaldays(bloomDay, m, k,mid)){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
