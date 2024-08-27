#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

void solve()
{
    int n;
	cin >> n;
	if (n == 1 || n == 2)
		cout << "1\n1";
	else  if (n == 3)
		cout << "2\n1 3";
	else
	{
		cout << n << el;
		for (int i = 1; i <= n / 2; i++)
			cout << 2 * i << " ";
		for (int i = 1; i <= (n - (n / 2)); i++)
			cout << 2 * i - 1 << " ";
	}
}

int main()
{
    adhamet
    
    int t = 1;
    //t = 4;
    while(t--) {
        solve();
    }
    return 0;
}
