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

int main()
{
    adhamet;
    setIO("blocks");

	map<char,int> alphabetMap;
	for (char letter='a'; letter<='z'; letter++)
		alphabetMap[letter]=0;

	int n;	cin >> n;
	for(int i = 0; i < n; i++) {
		map<char,int> word1,word2;
		for (char letter='a'; letter<='z'; letter++) {
			word1[letter]=0;
			word2[letter]=0;
		}

		string s1,s2;
		cin >> s1 >> s2;
		for(int i = 0; i < s1.size(); i++)
			word1[s1[i]]++;
		for(int i = 0; i < s2.size(); i++)
			word2[s2[i]]++;
			
		for(char letter='a'; letter<='z'; letter++)
			alphabetMap[letter]+=max(word1[letter],word2[letter]);
	}

	for(auto &itm: alphabetMap) {
		cout << itm.second << el;
	}
	
    return 0;
}