class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> ans;
        for(int i = 0; i < n1; i++) {
            int l = 0, r = n2-1, mid;
            while(l <= r) {
                mid = (l + r) / 2;
                if (nums2[mid] == nums1[i]) {
                    ans.insert(nums2[mid]);
                    break;
                }
                else if (nums2[mid] < nums1[i]){
                    l = mid + 1;
                } else if (nums2[mid] > nums1[i]) {
                    r = mid - 1;
                }
            }
        }

        vector<int> ansVec;
        for(auto it: ans)
            ansVec.push_back(it);
        return ansVec;
    }
};