class Solution {
public:
    int findansgth(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int zeroes = 0, ones = 0, ans = 0;
        
        hashmap[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] == 0 ? ++zeroes : ++ones;
            int diff = zeroes - ones;
            
            if (hashmap.count(diff)) {
                ans = max(ans, i - hashmap[diff]);
            } else {
                hashmap[diff] = i;
            }
        }
        
        return ans;
    }
};