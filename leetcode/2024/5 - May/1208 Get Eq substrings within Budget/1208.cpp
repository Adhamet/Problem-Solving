class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int i=0, j=0, sum=0, ans=0;
        while(j < n) {
            sum+=abs(s[j]-t[j]);

            if(sum <= maxCost) ans = max(j-i+1, ans);
            else {
                while(sum>maxCost && i<=j) {
                    sum-=abs(s[i]-t[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
