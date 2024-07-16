class Solution {
public:
    string reverse(string word, int s, int e) {
        if (s >= e) return word; 
        swap(word[s], word[e]);
        return reverse(word, s + 1, e - 1);
    }
    string reversePrefix(string word, char ch) {
        int pos = -1; 
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                pos = i;
                break;
            }
        }
        if (pos == -1) return word;
        return reverse(word, 0, pos);
    }
};
