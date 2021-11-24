#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define int long long
using namespace std;
const int MAXN = 5001;
const int MOD = 1e9 + 7;
int n , k , q;
int a[MAXN] , cnt[MAXN] , dp[MAXN][MAXN] , f[MAXN][MAXN];
void init()
{
    for (int i=1 ; i<=n ; i++)
    {
        dp[i][0] = 1;
    }
    for (int j=1 ; j<=k ; j++)
    {
        dp[1][j] = dp[2][j-1];
        dp[n][j] = dp[n-1][j-1];
        for (int i=2 ; i<n ; i++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1]) % MOD;
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=0 ; j<=k ; j++)
        {
            cnt[i] += dp[i][j] * dp[i][k - j];
            cnt[i] %= MOD;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> q;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
    }
    init();
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        ans += a[i] * cnt[i];
        ans %= MOD;
    }
    while(q--)
    {
        int i , x;
        cin >> i >> x;
        ans -= (a[i] * cnt[i]) % MOD;
        a[i] = x;
        ans += (a[i] * cnt[i]) % MOD;
        cout << ans << endl;
    }
    return 0;
}
