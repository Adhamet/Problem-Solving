#include <bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < n - 2; i++) {
            c1 ^= i;
            c2 ^= (i + 1);
        }

        i64 last = (1LL << 31) - 1;
        if(c1 != 0) {
            for(int i = 0; i < n - 2; i++)
                cout << i << ' ';
            c1 ^= last;
            cout << last << ' ' << c1 << el;
        } else {
			for(int i = 1; i <= n - 2; i++)
                cout << i << ' ';
            c2 ^= last;
            cout << last << ' ' << c2 << el;
        }
    }

    return 0;
}

