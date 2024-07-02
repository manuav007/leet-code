class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int p1=-1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                p1=i;
                break;
            }
        }
        if(p1==-1) return;
        for(int i=p1+1; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
        return;
    }
};
