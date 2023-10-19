#include <iostream>
#include <math>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    bool hasDecimal;
    int num;
    double x,n;
    
    int t;
    cin >> t;
    while(t--) {
        cin >> num;
        x = num / 180.00;
        n = (2.00) / (1.00 - x);
        hasDecimal = (((int) (round(n * 100))) % 100) != 0;
        if (hasDecimal) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}
