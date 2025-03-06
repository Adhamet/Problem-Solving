#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define pii pair<int,int>
#define int long long
#define el '\n'

int ans;
string input;
vector<pii> mem; // cnt, sum

pii recurse(int i) {
    if (i < 0) return {0,0};

    pii &ret = mem[i];
    if (ret.first != -1) return ret;

    ret = recurse(i - 1);

    if (input[i] == '{') ret.second += 1;
    else ret.second -= 1;

    if (ret.second < 0) {
        ret.first += 1;
        ret.second += 2;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int tc = 1;

    while (getline(cin, input)) {
        if (input[0] == '-') break;

        int n = (int)input.size();
        mem.assign(n, {-1,-1});

        pii res = recurse(n-1);
        cout << tc++ << ". " << res.first + res.second / 2 << el;
    }

    return 0;
}
