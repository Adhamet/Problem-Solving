#include <iostream>
using namespace std;

int main()
{
    int list[5];
    cout << "Please enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> list[i];
    }
    cout << "Perfect square of list numbers: ";
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            cout << list[i]*list[i] << ".";
            break;
        }
        cout << list[i]*list[i] << ", ";
        
    }
}