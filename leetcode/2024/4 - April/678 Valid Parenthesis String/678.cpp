class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;
        int n = s.size() - 1;

        for(int i = 0; i <= n; i++) {
            if(s[i] == '(' || s[i] == '*') open++;
            else open--;

            if(s[n-i] == ')' || s[n-i] == '*') close++;
            else close--;

            if(open < 0 || close < 0) return false;
        }

        return true;
    }
};
