class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), numOfZeros = 0;
        vector<int> answer(n, 0);
        int product = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) product *= nums[i];
            else numOfZeros++;
        }

        if(numOfZeros > 1) return answer;

        for(int i = 0; i < n; i++) {
            if(nums[i] != 0 && numOfZeros == 1) answer[i] = 0;
            else if(nums[i] != 0) answer[i] = product / nums[i];
            else answer[i] = product;
        }
               
        return answer;
    }
};