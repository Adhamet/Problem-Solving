#include <iostream>
#include <vector>
using namespace std;

struct date{
    int day,month,year;
};

struct product{
    int serialNum,quantity,salesPerDay[7];
    string name;
    char type;
    date expireDate;
}product[3];

int main()
{
    cout << "Please enter data of three products" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Values of Product Number #" << i+1 << "#" << endl;
        cout << "Serial Num: ", cin >> product[i].serialNum;
        cout << "Name: ", cin >> product[i].name;
        cout << "Expire Date (Day,Month,Year): ", cin >> product[i].expireDate.day >> product[i].expireDate.month
             >> product[i].expireDate.year;
        cout << "Quantity in the store: " , cin >> product[i].quantity;
        cout << "Type: " , cin >> product[i].type;
        cout << "7 values that represent sales for week days: ";
        for (int j = 0; j < 7; j++)
        {
            cin >> product[i].salesPerDay[j];
        }
    }
}