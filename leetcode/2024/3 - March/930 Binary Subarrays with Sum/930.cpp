/* Hashtable and Prefix Sum Approach (NEW DISCOVERY)
 * It is awesome how much an normal loop differs from builtin
 * functions in time. O(N)
 */
class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		int n = nums.size();
		int currSum = 0;
		int ans = 0;
		unordered_map<int, int> preFreq;

		for(int num: nums) {
			currSum += num;
			if(currSum == goal) ans++;

			if(preFreq.find(currSum - goal) != preFreq.end())
				ans += preFreqp[currSum - goal];

			preFreq[currSum]++;
		}
		return ans;
	}
};

/* Sliding Window approach (CREATIVE - NOT STRAIGHT FORWARD)
 * Calculates the sum of sizes. O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindow(nums, goal) - slidingWindow(nums, goal - 1);
    }
private:
    int slidingWindow(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, currSum = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            currSum += nums[r];

            while(l <= r && currSum > goal) {
                currSum -= nums[l++];
            }

            ans += (r - l + 1);
        }
        return ans;
    }
}; 
**/


/* Optimized Sliding Window Approach
 * Uses Zeros to make the solution faster. O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, currSum = 0, ans = 0, prefixZeros = 0;
        for(int r = 0; r < n; r++) {
            currSum += nums[r];

            while(l < r && (nums[l] == 0 || currSum > goal)) {
                if (nums[l] == 1) prefixZeros = 0;
                else prefixZeros += 1;
                currSum -= nums[l];
                l++;
            }

            if (currSum == goal) ans += 1 + prefixZeros;
        }
        return ans;
    }
};
**/