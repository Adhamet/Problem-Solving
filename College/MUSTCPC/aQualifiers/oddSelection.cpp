#include <iostream>
using namespace std;

int main()
{
    int t, arrL, chosen, ele;
    cin >> t;
    while (t--)
    {
        int even = 0, odd = 0;
        cin >> arrL >> chosen;
        for (int i = 0; i < arrL; i++)
        {
            cin >> ele;
            if (ele % 2 == 1) { odd++; }
            else even++;
        }
        if (odd % 2 == 0 || odd == 0 || odd > even || odd == even)
        {
            cout << "No\n";
        }
        else cout << "Yes\n";
    }
}