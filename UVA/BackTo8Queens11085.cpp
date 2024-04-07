#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int n = 8;
int mvs = 1e9;
vector<int> row(8), diag_pos(15), diag_neg(15);
vector<int> currAns;
vector<vector<int>> answers;
void search(int col) {
    if(col == 8) {
        answers.push_back(currAns);
        return;
    }

    for(int r = 0; r < 8; r++) {
        if(row[r] || diag_pos[r+col] || diag_neg[n-1-col+r]) continue;
        row[r] = diag_pos[r+col] = diag_neg[n-1-col+r] = 1;
        currAns.push_back(r);
        search(col+1);
        currAns.pop_back();
        row[r] = diag_pos[r+col] = diag_neg[n-1-col+r] = 0;
    }
};

int minDiff(vector<int> pos) {
    int minMvs = 10000;
    for(auto ans: answers) {
        int currMvs = 0;
        for(int i = 0; i < ans.size(); i++) {
            if (ans[i] + 1 != pos[i])
                currMvs++;
        }
        minMvs = min(minMvs, currMvs);
    }
    return minMvs;
}

int main()
{
    adhamet;

    search(0);
    vector<int> pos(8);
    int i = 1;
    while(cin >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5] >> pos[6] >> pos[7]) {
        printf("Case %d: %d\n", i++, minDiff(pos));
    }

    return 0;
}
