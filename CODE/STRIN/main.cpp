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
using namespace std;
int n;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
int f[MAXN][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    f[1][0] = 1;
    f[1][1] = 1;
    f[1][2] = 1;
    for (int i=2 ; i<=n ; i++)
    {
        f[i][0] = ((f[i-1][0] + f[i-1][1]) % MOD + f[i-1][2]) % MOD;
        f[i][1] = (f[i-1][0] + f[i-1][2]) % MOD;
        f[i][2] = ((f[i-1][0] + f[i-1][1]) % MOD + f[i-1][2]) % MOD;
    }
    int ans = 0;
    for (int j=0 ; j<=2 ; j++)
    {
        ans = (ans + f[n][j]) % MOD;
    }
    cout << ans;
    return 0;
}
