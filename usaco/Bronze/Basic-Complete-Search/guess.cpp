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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

// Internet approach
// The use of set is no other than making the code faster.
// Other than that, the code is pretty straight forward.
// Basically doing what I did but much faster in time complexity.
unordered_set<string> inter(const unordered_set<string> s1, const unordered_set<string> s2) {
	unordered_set<string> result;
	for(const string &i: s1) {
		if (s2.count(i)) result.insert(i);
	}
	return result;
}

int main()
{
	adhamet;
	setIO("guess");

	int n;	cin >> n;
	vector<unordered_set<string>> animals(n);
	for(int i=0; i<n; i++) {
		string name;
		int chars_num;
		cin >> name >> chars_num;
		for(int j=0; j<chars_num; j++) {
			string charact;
			cin >> charact;
			animals[i].insert(charact);
		}
	}

	int mx = 0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			unordered_set<string> common = inter(animals[i], animals[j]);
			mx = max(mx, (int)common.size()+1);
		}
	}
	cout << mx;

	return 0;
}

/* My approach O(n^4)
int main()
{
    adhamet;
    setIO("guess");

    int n;	cin >> n;
    unordered_map<string, vector<string>> animals;

    for(int i = 0; i < n; i++) {
    	string animal;	cin >> animal;
    	int k;	cin >> k;
    	vector<string> vec;
    	for(int j = 0; j < k; j++) {
    		string characteristic;	cin >> characteristic;
    		vec.push_back(characteristic);
    	}
    	animals[animal] = vec;
    }

    int mx = 1;
    for(const auto& [animal1, chars1] : animals) {
    	for(const auto& [animal2, chars2] : animals) {
	    	if (animal1 != animal2) {
	    		int curr_mx=1;
	    		for(const auto &str1 : chars1) {
	    			for(const auto &str2 : chars2) {
	    				if(str1 == str2) {
	    					curr_mx++;
	    					break;
	    				}
	    			}
	    		}
	    		mx = max(mx, curr_mx);
    		}
    	}
    }
    cout << mx;
	
    return 0;
} */