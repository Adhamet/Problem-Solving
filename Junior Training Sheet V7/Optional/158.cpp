#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int size, k;
    cin >> size >> k;
    
    int arr[size], count=0;
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    
    for(int i = 0; i < size; i++)
    {
        if(arr[i] >= arr[k-1] && arr[i] > 0) count++;
    }
        
    cout << count;
}
