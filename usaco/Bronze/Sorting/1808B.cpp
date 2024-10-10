#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
// -

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    int t;  cin >> t;
    while(t--) {
        int n,m;    cin >> n >> m;
        vector<vector<ll>> vec(n, vector<ll>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                cin >> vec[i][j];
        
        ll totlot = 0;
        for(int j = 0; j < m; j++) {
            vector<ll> player;
            for(int i = 0; i < n; i++) player.push_back(vec[i][j]);

            sort(player.begin(),player.end());

            for(int i = 0; i < n; i++) {
                // curr I in column contributing with a negative value
                totlot -= (n-i-1)*player[i];
                // curr I in column contributing with a positive value
                totlot += i*(player[i]);
            }
        }
        cout << totlot << el;
    }

	return 0;
}
