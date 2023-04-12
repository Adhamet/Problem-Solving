// Palindrome with Leading Zeros
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
    while(s.back() == '0')
    {
        s.pop_back();
    }
    string s2 = s;
    reverse(s2.begin(), s2.begin());
    if(s2 == s)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}