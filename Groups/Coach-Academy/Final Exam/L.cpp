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

const ll N = 1e15;

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

void testCase()
{
    int d, num1=1,num2=1;
    cin >> d;

    for(ll i = d+1; i <= N; i++)
        if(isPrime(i))
        {
            num1=i;
            break;
        }
    
    num2=num1*num1;
    for(ll i = num1+d; i < num2; i++)
        if(isPrime(i))
        {
            num2=i;
            break;
        }
    ll result = num1*num2;

    cout << result << el;
}

int main()
{
    adhamet
    int T;
    cin >> T;
    while(T--)
    {
        testCase();
    }
}