class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int _xor=0;
        for(int num: nums) {
            _xor ^= num;
        }

        return __builtin_popcount(_xor ^ k);
    }
};
