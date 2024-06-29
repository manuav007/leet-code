class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int h=s.size()-1;
        while(l<h){
            while(!isalnum(s[l]) && l<h) l++;
            while(!isalnum(s[h]) && l<h) h--;
            if(tolower(s[l])!=tolower(s[h])) return false;
            l++;
            h--;
        }
        return true;
    }
};
