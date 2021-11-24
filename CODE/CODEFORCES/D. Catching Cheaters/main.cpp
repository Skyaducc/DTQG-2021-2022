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
int n , m;
const int MAXN = 1001;
int dp[MAXN][MAXN];
string x , y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> x >> y;
    x = " " + x;
    y = " " + y;
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            if(x[i] == y[j])
            {
                dp[i][j] = dp[i-1][j-1]  + 2;
            }
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) - 1;
            ans = max(ans , dp[i][j]);
        }

    }
    cout << ans;
    return 0;
}
