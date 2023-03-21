#include <iostream>
using namespace std;

using ll = long long;

const int MAXN = 1e5+5;

ll f(ll n,ll r)
{
    if(n<10) return n+r*10;
    r = r*10 + n%10;
    return f(n/10,r);
}

ll X(ll);
ll Y(ll);

int x[MAXN], y[MAXN];

ll X(ll n)
{
    if(n==0) return 1;
    if(x[n]) return x[n];
    x[n] = X(n-1)+Y(n-1);
    return x[n];
}

ll Y(ll n)
{
    if(n==0) return 1;
    if(y[n]) return y[n];
    y[n] = X(n-1)*Y(n-1);
    return y[n];
}

ll apow(int base,int exp)
{
    if(exp==0) return 1;
    ll x = apow(2,exp/2);
    if(exp%2) return base*x*x;
    return x*x;
}

ll f3(ll n,int l,int r)
{
    int m = (l+r)>>1;
    ll a = apow(2,m), b = apow(2,m+1);
    if(a<=n && n<b) return m;
    else if(a>n) return f3(n,l,m-1);
    return f3(n,m+1,r);
}

int main()
{
    ll n; cin >> n;
    cout << "KQ1: " << f(n,0) << endl;
    cout << "KQ2: X(" << n << ") = " << X(n) << ", Y(" << n << ") = " << Y(n) << endl;
    cout << "KQ3: " << f3(n,0,62) << endl;
    return 0;
}