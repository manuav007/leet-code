class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long int y = x,d = 0;
        while(y > 0){
            d = (d * 10) + y % 10;
            y = y/10;
        }
        return x == d;
    }
};
