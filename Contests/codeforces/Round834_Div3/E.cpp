#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int potions[3][3] = {
		{2, 2, 3},
		{2, 3, 2},
		{3, 2, 2}
	};
	
	int t;
	cin >> t;
	
	while (t--) {
		ll n, h;
		cin >> n >> h;

		vector<ll> station(n);
		for (auto &astronaut: station) cin >> astronaut;
		sort(station.begin(), station.end());

		ll mxAbsorbed = 0;
		for (int i = 0; i < 3; i++) {
			ll absorbed = 0, currH = h;
			
			for (int j = 0, ptr = 0; j < n; j++) {
				if (currH > station[j]) currH += (station[j] / 2), absorbed += 1;
				else {
					while (currH <= station[j] && ptr < 3) {
						currH *= potions[i][ptr], ptr += 1;
					}

					if (currH > station[j]) currH += (station[j] / 2), absorbed += 1;
					else break;
				}
			}

			mxAbsorbed = max(mxAbsorbed, absorbed);
		}
		
		cout << mxAbsorbed << el;
	}

	return 0;
}
