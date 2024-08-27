class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        int bitmask = 0;

        for(char ch: word) {
            int chIdx = ch-'a';
            bitmask^=1<<chIdx;
            ans+=cnt[bitmask];
            for(int i = 0; i < 10; i++)
                ans += cnt[bitmask^(1<<i)];
            cnt[bitmask]++;
        }

        return ans;
    }
};
