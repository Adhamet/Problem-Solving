#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, lCount=0;
    string word;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        if(word.length() > 10)
        {
            for(int i = 0; i < word.length(); i++)
            {
                if(i == 0) { cout << word[i]; }
                else if (i == word.length() - 1) { cout << lCount << word[i]; }
                else{
                    lCount++;
                }
            }
            lCount = 0;
        }
        else { cout << word; }
        cout << endl;
    }
}