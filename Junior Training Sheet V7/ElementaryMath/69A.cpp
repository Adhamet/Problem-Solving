#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T, xFINAL=0, xTEMP, yFINAL=0, yTEMP, zFINAL=0, zTEMP;
    cin >> T;
    while(T--)
    {
        cin >> xTEMP >> yTEMP >> zTEMP;
        xFINAL += xTEMP;
        yFINAL += yTEMP;
        zFINAL += zTEMP;
    }
    if (!xFINAL && !yFINAL && !zFINAL)
    {
        cout << "YES";
    }
    else cout << "NO";
}
