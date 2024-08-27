class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }

private:
    int slidingWindow(vector<int>& nums, int k) {
        map<int, int> freq;
        int l = 0, cnt = 0;

        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }

            cnt += (r - l + 1);
        }
        return cnt;
    }

};
