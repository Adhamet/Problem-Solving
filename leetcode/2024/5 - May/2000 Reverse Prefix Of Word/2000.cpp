class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIdx = word.find(ch);
        if(chIdx == -1) return word;

        string ans;
        for(int i = 0; i < word.length(); i++) {
            if(i<=chIdx) ans += word[chIdx-i];
            else ans += word[i];
        }
        return ans;
    }
};
