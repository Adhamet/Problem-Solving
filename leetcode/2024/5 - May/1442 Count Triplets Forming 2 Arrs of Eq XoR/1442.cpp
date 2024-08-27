class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;

        for(int l = 0; l < arr.size()-1; ++l) {
            int xorA = 0;

            for(int mid = l + 1; mid < arr.size(); ++mid) {
                xorA ^= arr[mid - 1];

                int xorB = 0;

                for(int r = mid; r < arr.size(); ++r) {
                    xorB ^= arr[r];

                    if(xorA == xorB) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};
