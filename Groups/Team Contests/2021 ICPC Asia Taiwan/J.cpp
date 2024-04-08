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

    string s1,s2;	cin >> s1 >> s2;

    bool f = true;
    for(int i = 0; i < s1.size(); i++) {
    	if(s1[i] >= 'A' && s1[i] <= 'z') {
    		f = false;
    	}
    }

    for(int i = 0; i < s2.size(); i++) {
    	if(s2[i] >= 'A' && s2[i] <= 'z') {
    		f = false;
    	}
    }
	
	if(f) {
		int num1 = stoi(s1);
		int num2 = stoi(s2);
		cout << num1 - num2;
	}
	else {
		cout << "NaN";
	}

    return 0;
}