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


int main()
{
    adhamet;

    int n;	cin >> n;
    vector<pair<pair<int, int>, pair<int, string>>> countries(n);

    for (int i = 0; i < n; i++) {
        int g, s, b;
        string name;
        cin >> g >> s >> b;
        getline(cin, name);
        countries.push_back({{g, s}, {b, name}});
    }

    int mxG=0, mxS=0, mxB=0;
    string winner;
    for(auto country: countries) {
    	int g,s,b;
    	g = country.first.first;
    	s = country.first.second;
    	b = country.second.first;
    	string name = country.second.second;

        if(g > mxG || g == mxG && s > mxS || g == mxG && s == mxS && b > mxB) {
        	winner = name;
        	mxG = g;
        	mxS = s;
        	mxB = b;
    	}
    }

	for(int i = 1; i < winner.size(); i++) {
		cout << winner[i];
	}

    return 0;
}