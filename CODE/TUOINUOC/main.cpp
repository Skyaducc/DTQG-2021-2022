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
const int MAXN = 301;
int n;
int w[MAXN];
int a[MAXN][MAXN];
int dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> w[i];
    }
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            if(i != j)
            {
                dp[i] = min(dp[i-1] + w[i] , dp[j] + a[i][j]);
            }
        }
    }
    cout << dp[n];
    return 0;
}
