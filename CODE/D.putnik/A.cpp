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
const int MAXN = 1510;
int n;
ll res = 1e18;
ll dist[MAXN][MAXN] , hv[MAXN] , dd[MAXN];
ll dp[MAXN][MAXN][2];
void solve()
{
	// foru (i , 1 , n)	cout << hv[i] << " ";
	// cout << endl;
    bool check = true;
    foru (i , 1 , n)
    {
        int small = 0 , big = 0;
        foru (j , 1 , n)
        {
            if (hv[j] < hv[i])
            {
                if (j < i) small = 1;
                if (j > i) big = 1;
            }
            if (small + big > 1)
            {
                check = false;
                break;
            }
        }
        if (check == false) break;
    }
    if (check == true)
    {
        ll ans = 0;
        foru (i , 1 , n - 1) ans += dist[hv[i]][hv[i+1]];
        res = min(res , ans);
    }
}
void backtrack(int i)
{
    foru (j , 1 , n)
    {
        if (dd[j] == 0)
        {
            hv[i] = j;
            dd[j] = 1;
            if (i == n) solve();
            else backtrack(i + 1);
            dd[j] = 0;
        }
    }
}
void sub1 ()
{
	backtrack(1);
	cout << res;
}
void full()
{
	foru (i , 1 , n) foru (j , 1 , n) dp[i][j][0] = dp[i][j][1] = oo;
	dp[1][1][0] = dp[1][1][1] = 0;
	foru (i , 1 , n - 1) foru (j , 1 , i)
    {
        if (dp[i][j][0] < oo)
        {
            dp[i+1][j][0] = min(dp[i+1][j][0] , dp[i][j][0] + dist[i+1][i]);
            dp[i+1][i][1] = min(dp[i+1][i][1] , dp[i][j][0] + dist[j][i+1]);
        }
        if (dp[i][j][1] < oo)
        {
            dp[i+1][j][1] = min(dp[i+1][j][1] , dp[i][j][1] + dist[i][i+1]);
            dp[i+1][i][0] = min(dp[i+1][i][0] , dp[i][j][1] + dist[i+1][j]);
        }
    }
	foru (i , 1 , n) res = min(res , min(dp[n][i][0] , dp[n][i][1]));
	cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("putnik.inp" , "r" , stdin);
    freopen("putnik.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	foru (j , 1 , n)	cin >> dist[i][j];
    // sub1();
    full();
    return 0;
}