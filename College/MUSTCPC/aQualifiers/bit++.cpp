#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0, numOp;
    cin >> numOp;
    string operation;
    for(int i = 0; i < numOp; i++)
    {
        cin >> operation;
        if (operation[0] == '+' || operation[2] == '+')
        {
            x++;
        }
        else { x--; }
    }
    cout << x;
}