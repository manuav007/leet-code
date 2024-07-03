class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> count;
        unordered_map<int,int> start;
        unordered_map<int,int> end;
        int n = nums.size();
        int ma = 1;
        for(int i=0; i<n; i++){
            if(count.find(nums[i]) == count.end()){
                count[nums[i]]++;
                start[nums[i]] = i;
                end[nums[i]] = i;
            }
            else{
                count[nums[i]]++;
                end[nums[i]] = i;
                ma = max(ma,count[nums[i]]);
            }
        }
        int mi=INT_MAX;
        for(auto it: count){
            if(it.second == ma){
                mi = min(mi,end[it.first]-start[it.first]);
            }
        }
        return mi+1;
    }
};
