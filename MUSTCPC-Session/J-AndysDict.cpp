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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	string input, curr;
	set<string> st;

	while(cin >> input) {
		curr = "";
		for(int i = 0; i < input.size(); i++) 
		{
			char c = tolower(input[i]);
			if (isalpha(c)) curr += c;
			else if (curr != "") {
				st.insert(curr);
				curr = "";
			}
		}
		if (curr != "")
			st.insert(curr);
	}

	for(auto item: st) cout << item << el;
	
    return 0;
}