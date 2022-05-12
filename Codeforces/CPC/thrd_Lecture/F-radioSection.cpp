#include <iostream>
#include <string> 
#include <map>
 
using namespace std;
 
int main() 
{
    int n, m;
    cin >> n >> m;
 
    string tmp, ip;
    map<string, string> main, command;
    while (n--)
    {
        cin >> tmp >> ip;
        main[ip] = tmp;
    }
    while (m--)
    {
        cin >> tmp >> ip;
        string proIP = ip.substr(0, ip.length() - 1);
        command[proIP] = tmp;
 
        cout << command[proIP] << " " << proIP << "; #" << main[proIP] << endl;
    }
}