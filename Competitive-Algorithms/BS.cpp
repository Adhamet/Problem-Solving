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
// Iterative method: // LOG(N) ---------------------------------------------------------------------------

const bool KEY_NOT_FOUND = 0;
int BinarySearch(int A[], int key, int imin, int imax)
{
    while(imax >= imin)
    {
        int imid = midpoint(imin,imax);

        if(A[imid] < key)
            imin = imid + 1;
        else if(A[imid] > key)
            imax = imid - 1;
        else  
            return imid;
    }
    return KEY_NOT_FOUND;
}

// ---------------------------------------------------------------------------------------------------------


// Recursive method: ?? LOG(N) -----------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------------------------


// Find First And Find Last Technique: ---------------------------------------------------------------------

// 0 0 0 1 1 1 1
// MIN # 3rd index, Frst_Srch
// MAX # 6th index, Last_Srch

// Check to use [ start + (end-start)/2 ] OR [ start + (end-start+1/2) ] to avoid loops.
// by checking your equation with consecutive numbers.

int f(int a)
{
    // Any equation lies here
    int middle = ( a ) / 2;
    return middle;
}

// To Find Min(First):
int BSFindFirst(int start, int end, int val)
{
    while(start < end) {
        int mid = start + (end-start)/2;
        if(f(mid) < val) start = mid+1;
        else if(f(mid) > val) end = mid+1;
        // Why I dont break down here is that there may be multiple values
        // I need to find the best first value:
        else end=mid;        
    }
    return start;   
}

// To Find Max(Last):
int BSFindLast(int start, int end, int val)
{
    while(start < end) {
        int mid = start + (end-start)/2;
        if(f(mid) < val) start = mid+1;
        else if(f(mid) > val) end = mid+1;
        else start=mid;        
    }
    return start;   
}

// ---------------------------------------------------------------------------------------------------------


int can(int rand) { return 0; }
// Double Domain -------------------------------------------------------------------------------------------

// EPS guarantees that the number of zeroes are equal to what he asked.
double EPS = 1e2-10;
double BS_double(double start, double end, double val)
{
    while(fabs(end-start) > EPS) { // Problem is this may iterate 100~500 times.
                                   // There's another looping method below.
        double mid = start + (end-start)/2;
        if(f(mid) < val) start = mid;
        else             end = mid;
    }
    return start;
}

double binary(double start, double end)
{
    // Lets say 100
    for(int i = 0; i < 100; i++)
    {
        double mid = (start+end)/2;
        if ( can(mid) ) end = mid;
        else start = mid;
    }

    if( can(end) )
        return start;

    return -1; // failed
}