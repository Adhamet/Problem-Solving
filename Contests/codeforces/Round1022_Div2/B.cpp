#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        if (n == 1) {
            if (x == 0) {
                cout << -1 << endl;
            } else {
                cout << x << endl;
            }
        } else {
            if (x == 0) {
                if (n % 2 == 0) {
                    cout << 2 * (n - 1) << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                long long s = (n - 1) % 2;
                long long y = s ^ x;
                if (y != 0) {
                    cout << (n - 1) + y << endl;
                } else {
                    cout << (n + 3) << endl;
                }
            }
        }
    }
    return 0;
}
