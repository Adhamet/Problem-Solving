class Solution {
public:
    int lengthOfLastWord(string s) {
        string res = "";
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ' ' && !res.empty()) break;
            if(s[i] == ' ') continue;
            res.push_back(s[i]);
        }
        return res.length();
    }
};
