class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones_count = -1;
        string ans="1";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                ones_count++;
            }
            else {
                ans.insert(0,"0");
            }
        }
        while(ones_count--) {
            ans.insert(0,"1");
        }
        return ans;
    }
};