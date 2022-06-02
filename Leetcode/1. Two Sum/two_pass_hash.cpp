class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int size = nums.size();
        int diff;
        unordered_map<int, int> uom;
        for(int i = 0; i < size; i++)
        {
            diff = target - nums[i];
            if (uom.find(diff) != uom.end() && uom.find(diff)->second != i)
            {
                vec.push_back(i);
                vec.push_back(uom.find(diff)->second);
                return vec;
            }
            uom[nums[i]]=i;
        }
        return vec;
    }
};