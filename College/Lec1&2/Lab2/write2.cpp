#include <iostream>
using namespace std;

int main()
{
    int arr1[5], arr2[5], result[5];
    cout << "Enter first array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter second array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr2[i];
    }
    cout << "Result array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        result[i] = arr1[i] + arr2[i];
        cout << result[i] << " ";
    }
}