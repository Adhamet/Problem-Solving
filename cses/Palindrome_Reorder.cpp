#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T, class U = null_type, class chash = hash<T>> using hset = 
gp_hash_table<T,U,chash>;
template<class T, class U = null_type, class cmp = less<T>> using oset = 
tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pd = pair<ld,ld>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* BETTER ANSWER (not the best):
	Missing testcase:
 		What if there are multiples
		of that oddChar we found?
*/
int main()
{
	adhamet;
	// freopen("file.in", "r", stdin);
	// freopen("file.out", "w', stdout");

	string s;
	cin >> s;
	unordered_map<char,int> freq;
	int n = (int)s.size();

	vector<char> oddChars;
	for(int i = 0; i < n; i++)
		freq[s[i]]++;

	for(auto &entry: freq) if (entry.second % 2 != 0)
		oddChars.push_back(entry.first);

	if (oddChars.size() > 1) return cout << "NO SOLUTION", 0;

	string palindrome;
	for(auto &entry: freq) {
		string part(entry.second/2, entry.first);
		palindrome = part + palindrome + part;
	}

	if (!oddChars.empty())
        palindrome.insert(palindrome.size() / 2, 1, oddChars[0]);

	cout << palindrome;
}

/* MY ANSWER:
int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	string s;
	cin >> s;
	unordered_map<int,int> occ;
	deque<char> ft,bk;
	string odds="";
	int n = (int) s.size();

	for(int i = 0; i < n; i++)
		occ[s[i]]++;

	int mpS = (int) occ.size();
	if (mpS > ((n - 1) / 2)+1) return cout << "NO SOLUTION", 0;

	if (n % 2 == 0) {
		for(auto item: occ) {
			if (item.second % 2 != 0)
				return cout << "NO SOLUTION", 0;
			while(item.second > 0) {
				bk.push_back(item.first);
				ft.push_front(item.first);
				item.second -= 2;
			}
		}
	}
	else {
		for(auto item: occ) {
			if (item.second % 2 != 0) {
				while(item.second--)
					odds+=item.first;
			}
			else {
				while(item.second > 0) {
					bk.push_back(item.first);
					ft.push_front(item.first);
					item.second -= 2;
				}
			}
		}
	}

	while(!ft.empty()) { cout << ft.front(); ft.pop_front(); }
	cout << odds;
	while(!bk.empty()) { cout << bk.front(); bk.pop_front(); }
	return 0;
}*/
