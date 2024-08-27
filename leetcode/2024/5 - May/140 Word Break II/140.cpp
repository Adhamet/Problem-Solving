class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currSentence;
        vector<string> ans;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        solve(0, ans, s, dict, currSentence);
        return ans;
    }

    void solve(int pos, vector<string>& ans, string s, unordered_set<string>& dict, string& currSentence) {
        if (pos == s.size()) {
            ans.push_back(currSentence);
            return;
        }

        for (int i = pos+1; i <= s.size(); i++) {
            string word = s.substr(pos, i - pos);
            if (dict.find(word) != dict.end()) {
                string orgSentence = currSentence;
                if (!currSentence.empty()) currSentence += " ";

                currSentence += word;
                solve(i, ans, s, dict, currSentence);
                currSentence = orgSentence;
            }
        }
    }
};
