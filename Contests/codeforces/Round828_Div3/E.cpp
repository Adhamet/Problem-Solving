#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Start by setting x = a + 1 and y = b + 1
        int x = a + 1;
        int y = b + 1;

        // Check if x and y are within bounds
        if (x > c || y > d) {
            cout << "-1 -1" << endl;
            continue;
        }

        // Check if the product x * y is divisible by a * b
        if ((x * y) % (a * b) == 0) {
            cout << x << " " << y << endl;
        } else if (y + 1 <= d && (x * (y + 1)) % (a * b) == 0) {
            // Try increasing y by 1 if y+1 is still in the range
            cout << x << " " << y + 1 << endl;
        } else {
            // No valid pair found within constraints
            cout << "-1 -1" << endl;
        }
    }

    return 0;
}

