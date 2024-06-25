class Solution {
public:
    bool isValid(std::string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if(stk.empty()) return false; 
                if(s[i] == ')' && stk.top() == '(') stk.pop();
                else if(s[i] == '}' && stk.top() == '{') stk.pop();
                else if(s[i] == ']' && stk.top() == '[') stk.pop();
                else return false;
            }
        }
        return stk.empty(); 
    }
};
