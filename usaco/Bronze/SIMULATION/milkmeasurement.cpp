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

int main()
{
    adhamet;
	setIO("measurement");
    
	map<int, pair<string, int>> mapOfInput;

	int n;	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		string s;
		char op;
		int y;
		cin >> x >> s >> op >> y;

		if(op == '-') y = -y;
		mapOfInput[x] = {s,y};
	}

	int bessie=7,elsie=7,mildred=7;
	int displayChanges=0, mx_output=7;
	vector<string> display = {"Bessie", "Elsie", "Mildred"};
	for(auto const &day: mapOfInput) {
		string currentCow = day.second.first;
		int chgMilkOutput = day.second.second;
		if (currentCow == "Bessie")
			bessie += chgMilkOutput; // {7,9}
		else if(currentCow == "Mildred")
			mildred += chgMilkOutput;
		else if(currentCow == "Elsie")
			elsie += chgMilkOutput; // {7,6}

		mx_output = max( {bessie, mildred, elsie} );

		vector<string> new_display;
		if(bessie == mx_output) new_display.push_back("Bessie");
		if(mildred == mx_output) new_display.push_back("Mildred");
		if(elsie == mx_output) new_display.push_back("Elsie");

		displayChanges += (display != new_display);
		display = new_display;
	}
	cout << displayChanges;

    return 0;
}