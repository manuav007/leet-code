class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mpp;
        for (auto path : paths) {
            mpp[path[0]] = path[1];
        }
        string dest = paths[0][1];
        while(mpp.find(dest) != mpp.end()){
            dest = mpp[dest];
        }
        return dest;
    }
};
