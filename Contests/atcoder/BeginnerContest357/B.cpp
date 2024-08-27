#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* void setIO(string name = "") { */
/*     if (name.size()) { */
/*         freopen((name+".in").c_str(), "r", stdin); */
/*         freopen((name+".out").c_str(), "w", stdout); */    
/*     } */
/* } */

int main()
{
    /* setIO("cowqueue"); */
    adhamet;

 	string s;   cin >> s;
    int lowCount=0, upCount=0;
    for(int i = 0; i < s.size(); i++) {
        if(islower(s[i])) lowCount++;
        else if(isupper(s[i])) upCount++;
    }

    if(upCount > lowCount) {
        for(int i = 0; i < s.size(); i++) if(islower(s[i])) s[i] = toupper(s[i]);
    } else {
        for(int i = 0; i < s.size(); i++) if(isupper(s[i])) s[i] = tolower(s[i]);
    }

    cout << s << el;

    return 0;
}
