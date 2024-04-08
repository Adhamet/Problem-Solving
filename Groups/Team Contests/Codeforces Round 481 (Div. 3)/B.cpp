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

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }

int main()
{
    adhamet;
    // setIO("blist");

    int n;
    string s;
    cin >> n >> s;
 
    
    int count = 0;
    int result = 0;
 
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == "xxx") 
        {
            count++;
        }
    }
 
    result = count;
    cout << result << endl;
	
    return 0;
}