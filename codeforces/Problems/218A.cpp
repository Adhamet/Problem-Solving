#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'
int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	int n,k;
	cin >> n >> k;

	n = (n*2) + 1;
	vector<int> vec(n);

	for(int i = 0; i < n; i++) cin >> vec[i];

	for(int i = 0; i < n; i++)
	{
		if ( k != 0 && vec[i] > vec[i-1]+1 && vec[i] > vec[i+1]+1) {
			vec[i]--;
			k--;
		}
		cout << vec[i] << " ";
	}

	return 0;
}
