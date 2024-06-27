class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

public:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int step = mpp[word];
        for (int i = 0; i < word.size(); i++) {
            char orig = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == orig) continue;
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == step) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = orig;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        int size = beginWord.size();
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int step = mpp[word];
            q.pop();
            if (word == endWord) break;
            for (int i = 0; i < size; i++) {
                char orig = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == orig) continue;
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = step + 1;
                    }
                }
                word[i] = orig;
            }
        }
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
