#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int numS;
        cin >> numS;
        int *shoeSizes = new int[numS];
        int *rshoeSizes = new int[numS];
        for(int i = 0; i < numS; i++)
            cin >> shoeSizes[i];
        for(int i = 0; i < numS; i++)
        {
            int randIndex = rand() % (numS + 1);
            while(randIndex == i)
            {   
                randIndex = rand() % (numS + 1);
                if(shoeSizes[randIndex] >= shoeSizes[i])
                {
                    rshoeSizes[i] = shoeSizes[randIndex];
                }
                else randIndex == i;
            }
        }
        for(int i = 0; i < numS; i++)
        {
            if(shoeSizes[i] == rshoeSizes[i])
                return cout << "-1" << endl, 0;
        }
        for(int i = 0; i < numS; i++)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }
}