#include <bits/stdc++.h>
using namespace std;

#define adhamet ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define el '\n'
void setIO(string name = "");

set<int> possible;
void solve(int day, int fTank, vector<int> fBarn, int sTank,
                  vector<int> sBarn) {
    if (day == 4) {
        possible.insert(fTank);
        return;
    }
    for (int i = 0; i < fBarn.size(); i++) {
        int t = fBarn[i];
        vector<int> new_fBarn = fBarn;
        new_fBarn.erase(begin(new_fBarn) + i);
        vector<int> new_sBarn = sBarn;
        new_sBarn.push_back(t);

        solve(day + 1, sTank + t, new_sBarn, fTank - t, new_fBarn);
    }
}

int main()
{
    adhamet;
    setIO("backforth");

    vector<int> fBarn(10);
    for (int& i : fBarn) { cin >> i; }
    vector<int> sBarn(10);
    for (int& i : sBarn) { cin >> i; }

    solve(0, 1000, fBarn, 1000, sBarn);
    printf("%zu", possible.size());
    return 0;
}

void setIO(string name) {
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
