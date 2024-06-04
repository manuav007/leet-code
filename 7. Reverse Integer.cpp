class Solution {
public:
    int reverse(int x) {
        long long int d = 0;
        while(x){
            d=(d*10)+(x%10);
            x=x/10;
        }
        if (d > INT_MAX || d < INT_MIN) {
                return 0;
        }
        return (int)d;
    }
};
