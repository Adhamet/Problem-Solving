#include<bits/stdc++.h>

using namespace std;

#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back

#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)|(b))
#define XOR(a,b) ((a) ^ (b))
#define xx first
#define yy second
#define mp make_pair
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))

#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define left nokol_left
#define right nokol_right
#define countbit(x) __builtin_popcountll((ll)x)
#define PQ priority_queue
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<class T>T __sqr(const T x){return x*x;}
template< class T, class X > inline T __pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return __gcd(b,a%b);}
template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/__gcd(a,b))*b;}
inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);}
template<class T>void UpdateMin(T &x,T y){  if(y<x){x=y;}}
template<class T>void UpdateMax(T &x,T y){if(x<y){x=y;}}
template<class T,class X, class Y > inline T bigmod(T n,X m,Y mod){ull ret=1, a = n%mod ; while(m){ if(m&1)ret=(ret*a)%mod; m>>=1; a=(a*a)%mod; }ret%=mod;return (T)ret;}
template<class T, class Y > inline T modinv(T n,Y mod) {return bigmod(n,mod-2,mod);}

template<class T,class X> int getbit(T s,X i) { return (s >> i) & 1; }
template<class T,class X> T onbit(T s, X i) { return s | (T(1) << i); }
template<class T,class X> T offbit(T s, X i) { return s & (~(T(1) << i)); }
template<class T> inline void read(T &n){char c;for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar()); n = c - '0';for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';}

void extended_euclid(ll a,ll b,ll &x,ll &y){ if(!b){ x = 1 , y = 0  ;  return ;} ll xx,yy; extended_euclid(b,a%b,xx,yy); x = yy; y = xx - (a/b)*yy; }
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) { ll x = 1, y = 0; ll xLast = 0, yLast = 1; ll q, r, m, n; while(a != 0) {q = b / a; r = b % a; m = xLast - q * x; n = yLast - q * y; xLast = x, yLast = y; x = m, y = n; b = a, a = r; } return make_pair(b, make_pair(xLast, yLast)); }

const ll mod[]  ={0,1000000007,1000000009,1000000021,1000000033,1000000097,1000000093,1000000097,1000000103};
const ll base[] ={0,1000003,1000033,1000037,1000039,1000000081,1000000099,1000000117,1000000121};

#define pi acos(-1.0)
#define eps 1e-12
#define MX (lmt+20)
#define inf 1000000000000000000LL
#define MOD 1000000007LL
#define lmt 20000000

ll a[MX], vis[MX];
ll n, x, y;

void dfs(int u) {
    vis[u] = 1;
    
    for(int i = 2*u; i <= 2*n; i = i*2) {
        // Update current node using parent
        a[i] = min(a[i/2] + y, a[i]);
        
        // Update neighbors
        a[i-1] = min(a[i-1], a[i] + x);
        a[i+1] = min(a[i+1], a[i] + x);
        
        // Recursively visit unvisited neighbors
        if(i-1 >= 1 && !vis[i-1]) {
            dfs(i-1);
        }
        
        if(i+1 <= 2*n && !vis[i+1]) {
            dfs(i+1);
        }
    }
}

int main() {
    FAST;
    
    cin >> n >> x >> y;
    
    // Initialize array with initial costs
    rep(i,1,2*n) a[i] = a[i-1] + x;
    
    // Start DFS from node 1
    dfs(1);
    
    cout << a[n] << endl;
    return 0;
}
