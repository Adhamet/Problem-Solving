#include <bits/stdc++.h>
using namespace std;

#define adhamett ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamett

    int n, sum = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
        sum += i;

    cout << sum;

    return 0;
}