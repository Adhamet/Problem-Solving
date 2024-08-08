#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        ll x,y,k;  cin >> x >> y >> k;
        while(k>0) {
            if(x==1) {
                x+=k%(y-1);
                break;
            }
            x++, k--;
            if(x%y==0) while(x%y==0) x/=y;
            else {
                ll toModulo=y-x%y;
                x=x+toModulo, k-=toModulo;
                if(k<0) {
                    x+=k;
                    break;
                }
                while(x%y==0) x/=y;
            }
        }
        cout << x << el;
    }

    return 0;
}

