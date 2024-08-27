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

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }

int main()
{
    adhamet;
// 	setIO("blist");

    int n;  cin >> n;
    string org, correct_comb;   cin >> org >> correct_comb;
    
    int moves = 0;
    for (int i = 0; i < org.size(); i++) {
        int option1= abs( (org[i]) - correct_comb[i] );     // 1 - 7
        int option2= abs( (10+org[i]) - correct_comb[i] );  // 11 - 7
        int option3= abs( (10-org[i]) + correct_comb[i] );  // 
        moves += min( option1, min(option2,option3));
    } // 13
    cout << moves;
    
    return 0;
}
