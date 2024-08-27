#include <bits/stdc++.h>
using namespace std;

int n, target, sum = 0;
vector<int> CDs(25);
vector<int> curr, ans;

void recursion(int idx, int currSum) {
    if(idx == n) {
        if(currSum <= target && currSum > sum) sum=currSum, ans=curr;
        return;
    }

    if(CDs[idx] + currSum <= target) {
        curr.push_back(CDs[idx]);
        recursion(idx+1, currSum + CDs[idx]);
        curr.pop_back();
    }

    recursion(idx+1, currSum);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    while(cin >> target >> n) {
        curr.clear(), ans.clear();
        sum = 0;
        for(int i = 0; i < n; i++) cin >> CDs[i];

        recursion(0, 0);
        for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        printf("sum:%d\n", sum);
    }

    return 0;
}
