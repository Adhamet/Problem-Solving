// Soldier and bananas
#include <iostream>
using namespace std;

int main()
{
    int k,n,w,sum = 0;
    cin >> k >> n >> w;

    for (int i = 1; i <= w; i++)
        sum += i*k;
    
    int b = (sum - n) > 0 ? (sum - n) : 0;
    cout << b;
}