#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
#define EPS 1e-8
using ll = long long;
using ull = unsigned long long;

bool dcmp(double fval, double sval) {
    return fabs(fval - sval) < EPS;
}

struct pt {
    double x, y;
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    cout << "INTERSECTING LINES OUTPUT\n";
    while (t--) {
        pt pt1, pt2, pt3, pt4;
        cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y;
        cin >> pt3.x >> pt3.y >> pt4.x >> pt4.y;

        // ax + by + c = 0;
        double a1 = pt2.y - pt1.y;
        double b1 = pt1.x - pt2.x;
        double c1 = a1 * pt1.x + b1 * pt1.y;

        double a2 = pt4.y - pt3.y;
        double b2 = pt3.x - pt4.x;
        double c2 = a2 * pt3.x + b2 * pt3.y;

        cout << fixed << setprecision(2);
        if (dcmp(a1 * b2, a2 * b1)) {
            if (dcmp(a1 * c2, a2 * c1) && dcmp(b1 * c2, b2 * c1)) cout << "LINE" << el;
            else cout << "NONE" << el;
        } else {
            pt i;
            double det = a1 * b2 - a2 * b1;
            i.x = (b2 * c1 - b1 * c2) / det;
            i.y = (a1 * c2 - a2 * c1) / det;
            cout << "POINT " << i.x << " " << i.y << el;
        }
    }

    cout << "END OF OUTPUT" << el;
    return 0;
}
