class Solution {
public:
    int tribonacci(int n) {
        int T[n+5];
        T[0] = 0, T[1] = 1, T[2] = 1;
        for(int i = 3; i <= n; i++) {
            T[i] = T[i-1]+T[i-2]+T[i-3];
        }
        return T[n];
    }
};
