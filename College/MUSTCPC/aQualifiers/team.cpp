#include <iostream>
using namespace std;

int main()
{
    int numProg, Tonya, Petya, Vasya, temp, solved = 0;
    cin >> numProg;
    string input;
    for(int i = 0; i < numProg; i++)
    {
        cin >> Petya >> Tonya >> Vasya;
        if(Petya == 1 && Tonya == 1 || Vasya == 1 && Tonya == 1 || Petya == 1 && Vasya == 1)
        {
            solved++;
        }
    }
    cout << solved;
}