class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            int n = num%10;
            sum+=n;
            num = num/10;
        }
        if(sum>9) sum=addDigits(sum);
        return sum;
    }
};
