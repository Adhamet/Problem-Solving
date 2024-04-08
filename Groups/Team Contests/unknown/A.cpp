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

	string s;
	getline(cin, s);
	for(int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}    
	
	for(int i = 0; i < s.size()-1; i++) { // be
		if(s[i] == 'b' && s[i+1] == 'e') {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

    return 0;
}