#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

bool vis[20];
int n, votes[20], powerIdx[20], totalVotes, threshold;
void recursion(int idx, ll currVotes) {
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;

        vis[i] = true;
        if(currVotes + votes[i] > threshold) powerIdx[i]++;
        else if(i >= idx) recursion(i, currVotes + votes[i]);
        vis[i] = false;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif
    int t;  scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            votes[i] = 0, powerIdx[i] = 0, vis[i] = false;
        totalVotes = 0, threshold = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &votes[i]);
            totalVotes += votes[i];
        }
        threshold = (totalVotes / 2);

        recursion(0, 0);

        for(int i = 0; i < n; i++) printf("party %d has power index %d\n", i+1, powerIdx[i]);
        printf("\n");
    }
    return 0;
}
