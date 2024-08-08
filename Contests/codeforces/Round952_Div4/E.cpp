#include <iostream>
using namespace std;
#define ll long long
#define el '\n'

int main(){
	int t; cin >> t;
	while(t--){
        ll X, Y, Z, K;
        cin >> X >> Y >> Z >> K;

        ll maxWays = 0;
        for (ll x = 1; x <= X; ++x) {
            for (ll y = 1; y <= Y; ++y) {
                if (K % (x * y) == 0) {
                    ll z = K / (x * y);
                    if (z <= Z) {
                        ll ways = (X - x + 1) * (Y - y + 1) * (Z - z + 1);
                        maxWays = max(maxWays, ways);
                    }
                }
            }
        }

        cout << maxWays << el;
    }
}
