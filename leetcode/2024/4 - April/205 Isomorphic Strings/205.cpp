class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> idxT(200, 0);
        vector<int> idxS(200, 0);
        
        int n = s.length();
        if(n != t.length()) return false;
        
        for(int i = 0; i < n; i++) {
            if(idxS[s[i]] != idxT[t[i]]) return false;
            idxS[s[i]] = i + 1;
            idxT[t[i]] = i + 1;
        }
        
        return true;
    }
};
