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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}


const int WIDTH = 3;

vector<string> board(WIDTH);
set<set<char>> winners[WIDTH + 1];

void insert(vector<pair<int, int>> coordinates) {
	set<char> contained;
	for (const pair<int, int> &p : coordinates) {
		contained.insert(board[p.first][p.second]);
	}
	// add the amount of cows who contributed to this to the winners count
	winners[contained.size()].insert(contained);
}

int main()
{
    adhamet;
	setIO("tttt");

    for (int r = 0; r < WIDTH; r++) { cin >> board[r]; }

    // Searching rows -------------------------------
    for (int i = 0; i < WIDTH; i++) { insert({{i, 0}, {i, 1}, {i, 2}}); }
    
    // Searching columns ----------------------------
    for (int i = 0; i < WIDTH; i++) { insert({{0, i}, {1, i}, {2, i}}); }

    // Searching diagonals --------------------------
    insert({{0, 0}, {1, 1}, {2, 2}});
	insert({{2, 0}, {1, 1}, {0, 2}});

    // Output results;
    cout <<  winners[1].size() << el <<  winners[2].size();

    return 0;
}