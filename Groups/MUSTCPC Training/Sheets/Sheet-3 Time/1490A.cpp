// Dense Array
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    int t;
    cin >> t;
    while(t--)
    {
        int size,x,i;
        cin >> size;
        vector<int> vec(size);

        for(int i = 0; i < size; i++) cin >> vec[i];

        int mx,mn,count=0;

        for(int i = 0; i < size-1; i++) {
            mx = max(vec[i], vec[i+1]);
            mn = min(vec[i], vec[i+1]);

            while(mn * 2 < mx) 
            {
                mn *= 2;
                count++;
            }
        }

        cout << count << el;
    }

    return 0;
}