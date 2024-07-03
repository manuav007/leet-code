class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mpp;
        int n=candyType.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(mpp.find(candyType[i]) == mpp.end()){
                mpp[candyType[i]]++;
                count++;
            }
        }
        n = n/2;
        if(count>n){
            return n;
        }
        else{
            return count;
        }
    }
};
