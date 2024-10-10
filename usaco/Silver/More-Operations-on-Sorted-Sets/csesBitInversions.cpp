#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    string s;
    int m;
    cin >> s;
    cin >> m;

    bitset<200000> bits(s);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        bits[i] = (s[i] == '1');
    }

    vector<int> changes(m);
    for (int i = 0; i < m; i++) {
        cin >> changes[i];
        changes[i]--; // convert to 0-based index
    }

    auto find_longest_sequence = [&bits, n]() {
        int max_len = 1;
        int current_len = 1;
        for (int i = 1; i < n; i++) {
            if (bits[i] == bits[i-1]) {
                current_len++;
                max_len = max(max_len, current_len);
            } else {
                current_len = 1;
            }
        }
        return max_len;
    };

    for (int change : changes) {
        bits.flip(change);
        int longest_seq = find_longest_sequence();
        cout << longest_seq << " ";
    }

    return 0;
}
