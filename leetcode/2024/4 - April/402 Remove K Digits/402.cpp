class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k)
        return "0";

        string ans;
        vector<char> stk;

        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stk.empty() && stk.back() > num[i]) {
                stk.pop_back();
                --k;
            }
            stk.push_back(num[i]);
        }

        while (k-- > 0) stk.pop_back();

        for (const char c : stk) {
            if (c == '0' && ans.empty())
                continue;
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};
