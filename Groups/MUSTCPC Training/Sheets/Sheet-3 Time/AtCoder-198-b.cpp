// Palindrome with Leading Zeros
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

bool isPali(string str)
{
    int s = str.size();
    for(int i = 0; i < s; i++)   
        if(str[i] != str[s-(i+1)]) return false;
    return true;
}

int main()
{
    adhamet

    string n, N;
    cin >> n;
    N = n;

    if(isPali(n)) 
        return cout << "Yes", 0;
    
    while(n[n.size()-1] == '0')
    {
        N = '0'+N;
        n.pop_back();
    }

    if(isPali(N)) cout << "Yes";
    else cout << "No";

    return 0;
}