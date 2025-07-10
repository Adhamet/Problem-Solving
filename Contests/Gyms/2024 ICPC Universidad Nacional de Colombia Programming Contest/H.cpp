#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define int i64

string getRankName(int level) {
	if (level == 0) return "newbie";
	else if (level == 1) return "pupil";
	else if (level == 2) return "specialist";
	else if (level == 3) return "expert";
	else if (level == 4) return "candidate master";
	else if (level == 5) return "master";
	else return "grandmaster";
}

int getRankLvl(int x) {
	if (x <= 1199) return 0;
	else if (x <= 1399) return 1;
	else if (x <= 1599) return 2;
	else if (x <= 1899) return 3;
	else if (x <= 2099) return 4;
	else if (x <= 2399) return 5;
	return 6;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;	cin >> s;
	int curr, mx, delta;	cin >> curr >> mx >> delta;
	int after = curr + delta;
	int mxRank = getRankLvl(mx);
	int nRank = getRankLvl(after);
	if (nRank > mxRank) cout << getRankName(nRank);
	else cout << "Think about it, you can do it!";
	return 0;
}

