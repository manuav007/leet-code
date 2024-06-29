class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 1) return 1;
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if(length == 0){
                    continue;
                }
                break;
            }
            else {
                length++;
            }
        }
        return length;
    }
};
