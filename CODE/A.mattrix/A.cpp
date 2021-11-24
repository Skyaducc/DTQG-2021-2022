#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define ll long long
using namespace std;
const int oo = 1e9;
const int MOD = 1e9 + 7;
ll m , n;
ll ans = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mattrix.inp" , "r" , stdin);
    freopen("mattrix.out" , "w" , stdout);
    cin >> m >> n;
    foru (i , 1 , n) 
    {
        ans *= 1LL * min(1LL * i , m);
        ans %= MOD;
    }
    ford (i , m , 2) 
    {
        ans *= 1LL * min(n , m - i + 1);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
