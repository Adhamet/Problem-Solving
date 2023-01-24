#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, inside, largest;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        if (i == 0)
        {
            inside = b;
            largest = inside;
        }
        else
        {
            inside = (inside - a) + b;
            if (largest < inside) largest = inside;
        }
    } 
    cout << largest;
}