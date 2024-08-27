// Consider this problem: You are given N≤20 numbers, 
// each up to 10^9. Is there a subset with sum equal to given goal S ?
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet;

    int n;	scanf("%d",&n);
    ll goal; scanf("%ld",&goal);
    int numbers[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int mask = 0; mask < (1<<n); mask++) {
    	ll currSum = 0;
    	for(int i = 0; i < n; i++)
    		if(mask & (1<<i)) currSum += arr[i];
    	if(currSum == goal) return puts("YES"), 0;
    }
    puts("NO");
	
    return 0;
}