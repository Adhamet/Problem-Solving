#include <iostream>
#include <cmath>
using namespace std;

long long calculate_steps(long long distance, long long K) {
    long long groups = (distance + K - 1) / K; // Equivalent to ceil(distance / K)
    return distance + max(0LL, groups - 1);   // Add breaks if necessary
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        long long x1, y1, z1, x2, y2, z2, K;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> K;

        long long dx = abs(x2 - x1);
        long long dy = abs(y2 - y1);
        long long dz = abs(z2 - z1);

        // Calculate the minimum steps for each coordinate
        long long steps_x = calculate_steps(dx, K);
        long long steps_y = calculate_steps(dy, K);
        long long steps_z = calculate_steps(dz, K);

        // Sum up all the steps
        long long total_steps = steps_x + steps_y + steps_z;

        // Output the result for this test case
        cout << total_steps << endl;
    }
    return 0;
}

