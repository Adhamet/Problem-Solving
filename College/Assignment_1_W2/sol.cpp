#include <iostream>
using namespace std;

int main()
{
    int products[3][5], basePrice, taxes, maxPrice, netPrice;
    for (int i=0; i<3; i++)
    {
        cout << "Data of Product #" << i+1 << endl;
        cout << "Enter base price of product : ";
        cin >> basePrice;
        cout << "Enter taxes of product : ";
        cin >> taxes;
        cout << "Enter maximum price of the belonging production line : ";
        cin >> maxPrice;
        cout << "Product net price : ";
        cin >> netPrice;
        if (netPrice<maxPrice)
            cout << "product net price is accepted" << endl;
        else
            cout << "Product net price exceeds production line maximum price" << endl;
    }
}