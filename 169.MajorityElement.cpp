class Solution {
public:
    int majorityElement(vector<int>& nums) {
        long long int el;
        long int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                el = nums[i];
                count = 1;
            }
            else if(el == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return (int)el;
    }
};
