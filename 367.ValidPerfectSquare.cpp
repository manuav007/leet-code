class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int low=0;
        long long int high=num;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(mid*mid == num) return true;
            if(mid*mid > num) high = mid-1;
            else low=mid+1;
        }
        return false;
    }
};
