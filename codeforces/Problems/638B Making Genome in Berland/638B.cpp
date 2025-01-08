#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

string ans = "";
vector<bool> vis;
set<char> allChars;
map<char, vector<char>> in, out;
void dfs(char node) {
    if (vis[node - 'a']) return;
    ans += node;
    vis[node - 'a'] = true;
    if (!out[node].empty()) dfs(out[node][0]);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vis.resize(26, false);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) allChars.insert(c);
        if (s.size() > 1) {
            for (int j = 0; j < s.size() - 1; ++j) {
                out[s[j]].push_back(s[j + 1]);
                in[s[j + 1]].push_back(s[j]);
            }
        }
    }
    
    for (char c : allChars) if (in[c].empty()) {
		dfs(c);
    }
    
    return cout << ans, 0;
}
