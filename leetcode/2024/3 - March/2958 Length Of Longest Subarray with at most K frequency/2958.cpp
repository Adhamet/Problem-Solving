class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
            return 0;
            
        unordered_map<int,int> freq;
        int l = 0, r = 0, mx = 0;

        while(l < nums.size() && r < nums.size()) {
            freq[nums[r]]++;
            while(freq[nums[r]] > k) freq[nums[l]]--, l++;
            mx = max(mx, r-l+1), r++;
        }

        return mx;
    }
};

