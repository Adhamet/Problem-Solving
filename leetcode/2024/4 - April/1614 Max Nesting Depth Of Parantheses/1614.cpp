class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int mxDepth = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') stk.push(s[i]);
            else if (s[i] == ')') {
                if(stk.top() == '(')
                    stk.pop();
            }
            mxDepth = mxDepth < stk.size() ? stk.size(): mxDepth;
        }
        return mxDepth;
    }
};
