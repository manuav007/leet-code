class Solution {
public:
    int findGCD(vector<int>& nums) {
        long long int x = INT_MAX;
        long long int y = INT_MIN;
        for(long int num : nums){
            if(x > num){
                x=num;
            }
            if(y < num){
                y=num;
            }
        }
        while(x>0 && y>0){
            if(x>y){
                x=x%y;
            }else{
                y=y%x;
            }
        }
        if(x == 0){
            return y;
        }
        else{
            return x;
        }
    }
};
