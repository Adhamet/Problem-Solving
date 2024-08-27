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

// This approach is a huge improvement on the approach below..
// This solution is O(n^2), it saves two loops..
// Idea is to simply store the starts and finishes of each letter,
// so that you avoid the last 2 loops.
int main()
{
	adhamet;
	setIO("circlecross");

	string s;	cin >> s;

	vector<int> start(26, -1), end(26, -1);

	for(int i = 0; i < s.size(); i++) {
		if (start[s[i] - 'A'] == -1) {
			start[s[i] - 'A'] = i;
		}
		else {
			end[s[i] - 'A'] = i;
		}
	}

	int crossing_pairs = 0;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			crossing_pairs += (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]);
	cout << crossing_pairs;

	return 0;
}

/* Not the best Approach but works, O(n^4), it's very simple.
int main()
{
    adhamet;
    setIO("circlecross");

    string s;	cin >> s;

	int crossing_pairs = 0;
	for(int a = 0; a < s.size(); a++)
		for(int b = a+1; b < s.size(); b++)
			for(int c = b+1; c < s.size(); c++)
				for(int d = c+1; d < s.size(); d++)
					crossing_pairs += (s[a] == s[c] && s[b] == s[d]);
	cout << crossing_pairs;

    return 0;
} */