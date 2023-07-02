// Translation
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    string sRev, sTr;
    cin >> sRev >> sTr;
    reverse(sRev.begin(), sRev.end());
    
    if ( sRev == sTr )
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
