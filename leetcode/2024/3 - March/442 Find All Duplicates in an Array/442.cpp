class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> ans;
        for(int i = 0; i < n-1; i++) {
            if(v[i] == v[i+1]) {
                ans.push_back(v[i]);
                i++;
            }
        }
        return ans;
    }
};
