#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int temp,ones=0,zeros=0;
    string s;
    cin >> temp >> s;
    
    for(int i = 0; i < temp; i++)
    {
        if(s[i] == '1')
        {
            ones++;
        }
        else zeros++;
    }
    cout << abs(ones - zeros);
}
