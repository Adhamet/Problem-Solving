#include <bits/stdc++.h>
using namespace std;

int n, m, a[50], b[50];
bool vis[50], flag;

void recursion(int idx, int d) {
    if(idx == n) {
        if(d == a[1]) flag = true;
        return;
    }

    for(int i = 2; i < m+2; i++) {
        if(!vis[i]) {
            if(d == a[i]) {
                vis[i] = true;
                recursion(idx+1, b[i]);
                vis[i] = false;
            }
            if(d == b[i]) {
                vis[i] = true;
                recursion(idx+1, a[i]);
                vis[i] = false;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif

    while(scanf("%d", &n) && n) {
        scanf("%d", &m);

        for(int i = 0; i < m+2; i++) scanf("%d %d", &a[i], &b[i]);

        flag = false;
        recursion(0,b[0]);
        flag ? printf("YES\n"): printf("NO\n");
    }

    return 0;
}
