class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0, l = 0, r = 0;
        int n = nums.size();

        while(l < n && r < n) {
            if (nums[r] == maxElement) k--;
            while (!k) {
                if (nums[l] == maxElement) k++;
                l++;
            }
            ans += l, r++;
        }
        return ans;
    }
};
