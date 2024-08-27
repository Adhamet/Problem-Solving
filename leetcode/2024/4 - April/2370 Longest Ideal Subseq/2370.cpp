class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int best=0;
            int curr=s[i] - 'a';
            for(int j = 0; j < 26; j++) {
                if(abs(curr - j) <= k) best = max(best, dp[j]);
            }

            dp[curr] = max(dp[curr], best + 1);
            ans = max(ans, dp[curr]);
        }
        return ans;
    }
};
