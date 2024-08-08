#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* void setIO(string name = "") { */
/*     if (name.size()) { */
/*         freopen((name+".in").c_str(), "r", stdin); */
/*         freopen((name+".out").c_str(), "w", stdout); */    
/*     } */
/* } */

int main()
{
    /* setIO("cowqueue"); */
    adhamet;

 	int t;  cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        swap(a[0],b[0]);
        cout << a << " " << b << el;
    }

    return 0;
}
