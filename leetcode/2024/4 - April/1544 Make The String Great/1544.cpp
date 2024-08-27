class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;

        for(char c: s) {
            if(!stk.empty() && abs(c - stk.top()) == 32)
                stk.pop();
            else stk.push(c);
        }

        string res;
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};
