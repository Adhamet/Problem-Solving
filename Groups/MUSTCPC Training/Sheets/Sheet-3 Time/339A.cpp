// Helpful Maths
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    string s;
    cin >> s;
    vector<int> vec;
    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        if(s[i] != '+') vec.push_back(s[i] - '0');
    }

    sort(vec.begin(), vec.end());
    len = vec.size();
    for(int i = 0; i < len; i++)
    {
        cout << vec[i];
        if(i != len-1) cout << "+";
    }

    return 0;
}