// CSES - Task 1622
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    string s;	cin >> s;

    sort(s.begin(), s.end());

    vector<string> permutations;
    do {
    	permutations.push_back(s);
    } while(next_permutation(s.begin(),s.end()));

	cout << permutations.size() << el;
	for(const string& permutation: permutations)
		cout << permutation << el;

    return 0;
}

/**
 * Recursive method
 */
/*
string s;
vector<string> perms;
int char_count[26];

void search(const string &curr = "") {
    if(curr.size == s.size()) {
        // permutation found
        perms.push_back(curr);
        return;
    }

    for(int i = 0; i < 26; i++) {
        // Loop over all available characters
        if(char_count[i] > 0) {
            // Put it in its position in string
            // Then continue searching.
            char_count[i]--;
            search(curr + (char)('a'+i));
            char_count[i]++;
        }
    }
}

int main()
{
    cin >> s;
    for(char c: s) char_count[c - 'a']++;

    search();

    cout << perms.size() << el;
    for(const string &perm: perms) cout << perm << el;
}
*/