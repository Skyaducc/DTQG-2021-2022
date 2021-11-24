#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair <int , int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
#define getbit(i , x) ((x >> i) & 1)
#define oo (int)(1e18)
#define endl '\n'
#define task "FLOWERS"
using namespace std;
const int maxn = 1e6 + 10;
int frac[maxn] , finv[maxn] , p , n , m , k , q , cnt;
bool dd[maxn];
int prime[maxn] , cnt1[maxn];
int Power(int x , int y)
{
    if (!y) return 1;
    if (y == 1) return x % p;
    int ret = Power(x , y / 2);
    ret = 1ll * ret * ret % p;
    if (y % 2) ret = 1ll * ret * x % p;
    return ret;
}
void eratos()
{
    dd[0] = dd[1] = 1;
    FORU(i , 2 , 1000000)
    {
        if (!dd[i])
        {
            prime[++cnt] = i;
            for (int j = 2 * i; j <= 1000000; j += i) dd[j] = 1;
        }
    }
    prime[++cnt] = oo;
}
void init()
{
    frac[0] = finv[0] = 1;
    FORU(i , 1 , 1000000)
    {
        frac[i] = 1ll * frac[i - 1] * i % p;
        finv[i] = Power(frac[i] , p - 2);
    }
}
int sub2(int k , int n)
{
    return 1ll * frac[n] * finv[k] % p * finv[n - k] % p;
}
int cal(int m , int k)
{
    return 1ll * m * Power(m - 1 , k) % p;
}
int sub3(int k , int n)
{
    int res = finv[k];
    FORU(i , 0 , k - 1) res = 1ll * res * (n - i) % p;
    return res;
}
int Get(int d , int n)
{
    int ret = 0;
    int tmp = d;
    while (1)
    {
        ret += n / d;
        if (d > n / tmp) break;
        d *= tmp;
    }
    return ret;
}
int sub4()
{
    int ret = 1 , i = 1;
    while (prime[i] <= n)
    {
        int tmp = Get(prime[i] , n) - Get(prime[i] , k) - Get(prime[i] , n - k);
        ret = (1ll * ret * Power(prime[i] , tmp)) % p;
        i++;
    }
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    cin >> q >> p;
    if (p != 220797) init();
    else eratos();
    while (q--)
    {
        cin >> n >> m >> k; n--;
        if (k > n)
        {
            cout << "0\n";
            continue;
        }
        if (p == 220797)
        {
            cout << 1ll * sub4() * cal(m , k) % p << "\n";
            continue;
        }
        if (n < maxn) cout << 1ll * sub2(k , n) * cal(m , k) % p << "\n";
        else cout << 1ll * sub3(k , n) * cal(m , k) % p << "\n";
    }
    return 0;
}