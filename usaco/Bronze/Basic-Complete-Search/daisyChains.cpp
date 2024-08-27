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
    
    int n;  cin >> n;

    vector<int> flowers(n);
    for(int &f: flowers) cin >> f;

    int valid_photos = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            double avg_petals = 0;
            for(int f = i; f <= j; f++) avg_petals+=flowers[f];
            avg_petals /= (j - i + 1);

            for(int f = i; f <= j; f++) if(flowers[f] == avg_petals) {
                valid_photos++;
                break;
            }
        }
    }
    cout << valid_photos;

    return 0;
}