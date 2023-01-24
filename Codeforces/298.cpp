#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

void solve()
{
    int size;
    cin >> size;

    string str;
    cin >> str;

    pair<bool, char> foundFirst(false, 'a');
    bool foundSecond = false;
    int firstIndex, secondIndex;
    for(int i = 0; i < size; i++)
    {
        if( !foundFirst.F )
        {
            if( str[i] == 'R' )
                foundFirst.F = true, foundFirst.S = 'R', firstIndex = i;
            else if ( str[i] == 'L' )
                foundFirst.F = true, foundFirst.S = 'L', firstIndex = i;
        }
        else
        {
            if ( foundFirst.S == 'R' )
            {
                if ( str[i] == 'L' )
                {
                    cout << firstIndex << " " << i << el;
                    break;
                }
            }
            else if ( foundFirst.S == 'L' )
            {
                if ( str[i] == 'R' )
                {
                    cout << firstIndex << " " << i << el;
                    break;
                }
            }
            
            if ( (str[i+1] == '.' || str[i+1] == '\0') )
            {
                if ( foundFirst.S == 'R' )
                {
                    cout << firstIndex+1 << " " << i+1 << el;
                    break;
                }
                else
                {
                    cout << i << " " << firstIndex << el;
                    break;
                }
            }
        }
    }
}

int main()
{
    //adhamet

    solve();

    return 0;
}