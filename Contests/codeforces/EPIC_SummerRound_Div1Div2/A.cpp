#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


int main()
{
    adhamet;

    int t;  cin >> t;

    while(t--) {
        int a,b;    cin >> a >> b;

        ll time = 0;

        while(a--) {
            time+=b;
        }

        time -= (b-1);
        cout << time << el;
    }

    return 0;
}
