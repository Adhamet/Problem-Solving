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

    int n, limak;	cin >> n >> limak;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

   	int ans = 0;
    if(arr[--limak] == 1) ans++;
    int l = limak - 1, r = limak + 1; // 1,3
	while(true) {
		if(l>=0 && r<n && arr[l] == 1 && arr[r] == 1) // 1,0
			ans+=2;
		else if(!(l>=0) && r<n && arr[r] == 1) ans+=1;
		else if(l>=0 && !(r<n) && arr[l] == 1) ans+=1;
		else if(!(l>=0) && !(r<n)) break;
		l--,r++;
	}
	cout << ans;
	
    return 0;
}