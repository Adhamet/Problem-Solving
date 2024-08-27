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
    setIO("traffic");

    int n, A[100], B[100];
    string segment_type[100];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> segment_type[i] >> A[i] >> B[i];

    int a=0, b=1e9;
	for(int i=n-1; i>=0; i--) {
		if(segment_type[i] == "on") {
			a -= B[i];
			b -= A[i];
			a = max(0,a);
		}
		else if(segment_type[i] == "off") {
			a += A[i];
			b += B[i];
		}
		else {
			a = max(a,A[i]);
			b = min(b,B[i]);
		}
	}
	cout << a << " " << b << el;

	a=0, b=1e9;
	for(int i = 0; i < n; i++) {
		if(segment_type[i] == "off") {
			a -= B[i];
			b -= A[i];
			a = max(0,a);
		}
		else if(segment_type[i] == "on") {
			a += A[i];
			b += B[i];
		}
		else {
			a = max(a,A[i]);
			b = min(b,B[i]);
		}
	}
	cout << a << " " << b << el;

    return 0;
}