    class Solution {
    public:
        int specialArray(vector<int>& nums) {
            map<int, int> cnt;
            for(int num: nums) cnt[num]++;

            int tot = nums.size();
            for(int i = 0; i < 1000; i++) {
                if(i == tot) return i;
                tot -= cnt[i];
            }
            return -1;
        }
    };
