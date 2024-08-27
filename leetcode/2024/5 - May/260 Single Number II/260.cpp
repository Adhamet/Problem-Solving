class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x,y;
        bool takenX=false, takenY=false;

        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i==0) {
                if(nums[i]!=nums[i+1]) {
                    if(!takenX) x = nums[i], takenX = true;
                    else y = nums[i], takenY = true;
                }
            } else if (i==nums.size()-1) {
                if(nums[i]!=nums[i-1]) {
                    if(!takenX) x = nums[i], takenX = true;
                    else y = nums[i], takenY = true;
                }
            } else if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) {
                if(!takenX) x = nums[i], takenX = true;
                else y = nums[i], takenY = true;
            }
        }

        return {x,y};
    }
};
