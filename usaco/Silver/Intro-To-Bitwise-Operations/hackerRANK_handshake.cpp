#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int add(int a, int b) {
	int _and = (a&b);
	int _xor = ~(a&b) & (a|b);

	return 2*_and + _xor;
}

int main()
{
	int t;	scanf("%d", &t);
	while(t--) {
		int ppl;	scanf("%d", &ppl);
		
		int hs = 0, a = ppl, b = ppl-1;
		
		while(b>0) {
			if(b&1 == 1) hs = (2*(hs&a)) + (hs^a);

			a<<=1, b>>=1;
		}

		printf("%d\n", hs/2);
	}

    return 0;
}

// int main()
// {
// 	int t;	scanf("%d", &t);
// 	while(t--) {
// 		int ppl;	scanf("%d", &ppl);
		
// 		int handshakes = 0;
// 		for(int i = 0; i < ppl; i++) { // 1 
// 			handshakes = add(handshakes, ppl-i-1);
// 		}
// 		printf("%d\n", handshakes);
// 	}

//     return 0;
// }