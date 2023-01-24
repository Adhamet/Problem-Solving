#include <bits/stdc++.h>
using namespace std;

int main()
{
    int givenYear;
    string s;
    cin >> givenYear;
    while(true)
    {
        givenYear++;
        s=to_string(givenYear);
        if(s[0]!=s[1]&&s[0]!=s[2]&&s[0]!=s[3]&&s[1]!=s[2]&&s[1]!=s[3]&&s[2]!=s[3])
        {
            cout << s << endl;
            break;
        }
    }
}