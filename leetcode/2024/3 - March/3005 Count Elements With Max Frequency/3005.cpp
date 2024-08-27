class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(const int& num: nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        long long sum = 0;
        for(const auto& itm: freq) if (itm.second == maxFreq) {
            sum += itm.second;
        }
        return sum;
    }
};