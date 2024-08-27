class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> freq;
        map<char,bool> took;
        for(auto ch: s)
            freq[ch]++;
        
        string ans = "";
        for(int i = 0; i < s.size() && i < order.size(); i++) {
            if(freq[order[i]]) while (freq[order[i]]--) 
                ans += order[i];
            took[order[i]] = true;
        }
        for(int i = 0; i < s.size(); i++) if(!took[s[i]]) {
             ans+=s[i];
        }

        return ans;
    }
};