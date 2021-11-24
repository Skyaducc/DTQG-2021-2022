#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define FORU(i , a , b) for (int i = a ; i <= b ; i++)
#define FORD(i , a , b) for (int i = a ; i >= b ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define oo (ll)1e18
#define task "garden"
using namespace std;
const int maxn = 2210;
ll dp[maxn][maxn] , best[maxn][maxn][5];
int dx[] = {0 , -1 , 0 , 1 , 0};
int dy[] = {0 , 0 , -1 , 0 , 1};
int a[maxn][maxn] , n , m , k;
ll res = -oo;
/*
                1
                |
                |
          2-----X-----4
                |
                |
                3
                                */
void input()
{
    cin >> m >> n >> k;
    FORU(i , 1 , m) FORU(j , 1 , n) cin >> a[i][j];
}
void maximize(ll &a , ll b)
{
    a = max(a , b);
}
void solve(int t)
{
    for (int j = 1 ; j <= n ; j++)
    {
        for (int i = 1 ; i <= m ; i++)
        {
            ll &cur = dp[i][j];
            FORU(t , 1 , 4)
            {
                int nI = i + dx[t];
                int nJ = j + dy[t];
                maximize(cur , best[nI][nJ][t]);
            }
            if (i > 1) maximize(cur , dp[i - 1][j - 1]);
            maximize(cur , dp[i][j - 1]);
            if (i < n) maximize(cur , dp[i + 1][j - 1]);
            cur += a[i][j];
        }
    }
    memset(best , -0x3f , sizeof(best));
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            for (int t = 1 ; t <= 2 ; t++)
            {
                ll &cur = best[i][j][t];
                int nI = i + dx[t];
                int nJ = j + dy[t];
                maximize(cur , dp[i][j]);
                maximize(cur , best[nI][nJ][t]);
            }
            if (j == n) maximize(res , dp[i][j]);
        }
    }
    for (int i = m ; i >= 1 ; i--)
    {
        for (int j = n ; j >= 1 ; j--)
        {
            for (int t = 3 ; t <= 4 ; t++)
            {
                ll &cur = best[i][j][t];
                int nI = i + dx[t];
                int nJ = j + dy[t];
                maximize(cur , dp[i][j]);
                maximize(cur , best[nI][nJ][t]);
            }
        }
    }
}
void output()
{
    memset(dp , -0x3f , sizeof(dp));
    memset(best , -0x3f , sizeof(best));
    FORU(i , 1 , m) dp[i][0] = 0;
    FORU(t , 0 , k)
    {
        solve(t);
        memset(dp , -0x3f , sizeof(dp));
    }
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    output();
    return 0;
}