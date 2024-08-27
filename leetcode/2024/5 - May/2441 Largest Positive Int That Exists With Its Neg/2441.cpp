class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        for(int i : nums) {
            for(int j : nums) {
                if(i==-j) ans = max(ans,abs(i));
            }
        }

        return ans;
    }
};
