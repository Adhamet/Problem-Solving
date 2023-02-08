// LOG(N)
#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

int midpoint(int a, int b)
{
    int middle = ( a + b ) / 2;
    return middle;
}

const bool KEY_NOT_FOUND = 0;
int BinarySearch(int A[], int key, int imin, int imax)
{
    if (imax < imin) { // check if array is empty 
        return KEY_NOT_FOUND;
    }
    else 
    {
        int imid = midpoint(imin, imax);
        
        if(A[imid] < key)
            return BinarySearch(A, key, imin, imid-1);
        else if(A[imid] < key)
            return BinarySearch(A, key, imid+1, imax);
        else
            return imid;
    }
}

int main()
{
    return 0;
}