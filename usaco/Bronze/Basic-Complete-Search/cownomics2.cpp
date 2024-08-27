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
    setIO("cownomics");

    int n;  cin >> n;
    int m;  cin >> m;
    vector<string> spotty(n);
    vector<string> plain(n);

    for(int i = 0; i < n; i++) cin >> spotty[i];
    for(int i = 0; i < n; i++) cin >> plain[i];

    set<string> forspotty;

    int result = 0;
    string s(3, '0');
    bool good;

    for(int a = 0; a < m; a++) {
        for(int b = a+1; b < m; b++) {
            for(int c = b+1; c < m; c++) {
                good = true;
                forspotty.clear();
                for(int cow = 0; cow < n; cow++) {
                    s[0] = spotty[cow][a];
                    s[1] = spotty[cow][b];
                    s[2] = spotty[cow][c];
                    forspotty.insert(s);
                }

                for(int cow = 0; cow < n; cow++) {
                    s[0] = plain[cow][a];
                    s[1] = plain[cow][b];
                    s[2] = plain[cow][c];
                    if(forspotty.count(s)) {
                        good = false;
                        break;
                    }
                }

                if(good) result++;
            }
        }
    }
    cout << result << el;

    return 0;
}