class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n+1) / 2;
        double ans = sqrt(sum);

        if (ans - ceil(ans) == 0)
            return int(ans);
        else
            return -1;
    }
};
/*class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        if(n < 8) return -1;
        int x, xToN;
        for(int i = 6; i < n; i++) {
            x = (i*(i+1))/2;
            xToN = 0;
            for(int j = i; j <= n; j++) {
                xToN += j;
            }
            if(x == xToN) return i;
        }
        return -1;
    }
};*/