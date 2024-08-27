#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int init_y = y;

        vector<int> chosen(x);
        for (int &i: chosen) cin >> i;
        
        sort(begin(chosen), end(chosen));

        int ans = x - 2;
        int triangles_evenGaps = 0;

        vector<int> oddGaps;



        auto process_gap = [&](int g) -> void {
            if (g <= 1) ans += g;
            else if (g % 2 == 1) oddGaps.push_back(g / 2);
            else triangles_evenGaps += (g / 2);
        };



        for (int i = 0; i < x - 1; i++) {
            process_gap(chosen[i + 1] - chosen[i] - 1);
        }

        process_gap( (chosen[0] + n) - chosen[x - 1] - 1);

        sort(begin(oddGaps), end(oddGaps));

        for (int g: oddGaps) {
            if (y >= g) {
                ans += g + 1;
                y -= g;
            } else {
                ans += y;
                y = 0;
                break;
            }
        }

        int evenTriangles = min(triangles_evenGaps, y);
        y -= evenTriangles;
        ans += evenTriangles;

        int used_vertices = init_y - y;
        ans += used_vertices;

        cout << ans << el;
    }

    return 0;
}
