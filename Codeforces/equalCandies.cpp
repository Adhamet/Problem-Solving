/* Algorithm #1: Brute Force (Time: 62ms, Memory: 200kb) --------------------

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, smallest_index, eaten = 0;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if ( i == 0 ) smallest_index = i;
            else if ( arr[smallest_index] > arr[i] ) smallest_index = i;
        }
        for (int i = 0; i < n; i++)
            if ( i != smallest_index )
                    eaten += (arr[i] - arr[smallest_index]);
        cout << eaten << endl;
    }
}
-------------------------------------------------------------------------------*/

/* Algorithm #2: Vector Method (Time: 30ms, Memory: 0kb) --------------------- */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        int min = *min_element(vec.begin(),vec.end());
        int final = 0;
        for(int i = 0; i < n; i++) {
            vec[i] -= min;
            final += vec[i];
        }
        cout << final << endl;
    }
}

/* Algorithm #3: Sorting Method (Time: 15ms, Memory: 400kb) ----------------
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, c = 0;
        cin >> n;
        
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(a, a+n);
        
        for (int i = 1; i < n; i++) {
            c += a[i] - a[0];
        }
        cout << c << endl;
    }
}
