#include <bits/stdc++.h>
using namespace std;

char nums[10][8] = {
        "YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY",
        "YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"
};
vector<string> countdown;
bool recursion(int idx, int remain, vector<bool>& dmged) {
    if(remain == 0) return true;
    string currNum = countdown[countdown.size() - remain];
    string num = nums[idx];
    for(int i = 0; i < 7; i++) {
        if(dmged[i] && currNum[i] == 'Y') return false;
        else if(num[i] == 'N' && currNum[i] == 'Y') return false;
        else if(num[i] == 'Y' && currNum[i] == 'N') dmged[i] = true;
    }
    return recursion(idx-1, remain-1, dmged);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif

    int n;
    string in;
    while(scanf("%d", &n) && n) {
        countdown.clear();
        for(int i = 0; i < n; i++) {
            cin >> in;
            countdown.push_back(in);
        }

        bool accepted = false;
        for(int i = 9; i-n+1 >= 0 && !accepted; i--) {
            vector<bool> damaged(7, false);
            accepted = recursion(i, n, damaged);
        }

        accepted ? printf("MATCH\n"): printf("MISMATCH\n");
    }

    return 0;
}
