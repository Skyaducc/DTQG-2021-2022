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
const int MOD = 998244353;
const int MAXN = 1e6 + 1;
int n;
int dp[MAXN][4];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    dp[4][1] = 1;
    dp[4][2] = 1;
    dp[4][3] = 1;
    for (int i=4 ; i<=2*n ; i+=2)
    {
        for (int j=1 ; j<=3 ; j++)
        {
            for (int k=1 ; k<=3 ; k++)
            {
                if(j != k)
                {
                    dp[i][j] += dp[i-2][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i=1 ; i<=3 ; i++)
    {
        ans += dp[n*2][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
