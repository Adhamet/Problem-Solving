#include <iostream>
#include <string>
using namespace std;

int main()
{
    int stop, j = 0;
    cin >> stop;
    string arr[5] = {
        "Sheldon",
        "Leonard",
        "Penny",
        "Rajesh",
        "Howard"
    };
    int rep = 1;
    while (rep * 5 < stop)
    {
        stop -= rep * 5;
        rep *= 2;
    }
    cout << arr[(stop - 1) / rep] << endl;
}