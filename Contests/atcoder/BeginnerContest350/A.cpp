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
 	string s;	cin >> s;
 	int contestNum = stoi(s.substr(3,3));
 	if(contestNum < 350 && contestNum > 0 && contestNum != 316) printf("Yes");
 	else printf("No");
	
    return 0;
}