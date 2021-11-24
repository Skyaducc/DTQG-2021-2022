#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
using namespace std;
const int oo = 1e9;
const int MAXN = 1e6 + 11;
int n;
int a[MAXN];
int Gcd[MAXN] , R_gcd[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n) cin >> a[i];
    if(n == 1)
    {
        cout << 1000000000 << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << max(a[1] , a[2]) << endl;
        return 0;
    }
    Gcd[1] = a[1];
    R_gcd[n] = a[n];
    foru (i , 2 , n)
    {
        Gcd[i] = __gcd(Gcd[i-1] , a[i]);
    }
    ford (i , n - 1 , 1)
    {
        R_gcd[i] = __gcd(R_gcd[i+1] , a[i]);
    }
    int ans = 0;
    foru (i , 2 , n - 1)
    {
        ans = max(ans , __gcd(Gcd[i-1] , R_gcd[i+1]));
    }
    cout << ans;
    return 0;
}
