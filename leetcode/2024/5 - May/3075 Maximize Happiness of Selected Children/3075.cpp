class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size(), i = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long mx = 0;
        while(k--) {
            if(happiness[i]-i > 0) mx += happiness[i]-i, i++;
            else break;
        }
        return mx;
    }
};
