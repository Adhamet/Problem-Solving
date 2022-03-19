#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect; int num;
    cout << "Please enter the numbers: ";
    while(cin >> num) {
        vect.push_back(num);
    }
    for (auto itr = vect.begin(); itr != vect.end(); ++itr)
    {
        cout << *itr << endl;
    }
}
