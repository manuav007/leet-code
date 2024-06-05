class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> st;
        for (auto s : nums) {
            st.insert(s);
        }
        int longest = 0;
        for (auto s : st) {
            if (st.find(s - 1) == st.end()) {
                int current_num = s;
                int count = 1;
                while (st.find(current_num + 1) != st.end()) {
                    current_num++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
