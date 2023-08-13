#include <iostream>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
    {
        string ans = "YES\n";
        int n,b;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n ; i++) cin >> arr[i];
        
        bool x=false,y=false;
        for(int i = 0; i < n; i++) {
            cin >> b;
            if (arr[i] < b && !x) ans = "NO\n";
            else if (arr[i] > b && !y) ans = "NO\n";
            if (arr[i] == 1) x = true;
            else if (arr[i] == -1) y = true;
        }
        cout << ans;
    }
    return 0;
}
