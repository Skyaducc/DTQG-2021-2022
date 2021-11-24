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
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 1e5 + 1;
int n , W;
int w[MAXN] , v[MAXN];
int dp[101][MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> W;
    foru (i , 1 , n)
    {
    	cin >> w[i] >> v[i];
    }
    foru (i , 1 , n)
    {
    	foru (j , 0 , W)
    	{
    		dp[i][j] = max(dp[i][j] , dp[i-1][j]);
    		if(j >= w[i]) dp[i][j] = max(dp[i][j] , dp[i-1][j-w[i]] + v[i]);
    	}
    }
    int ans = 0;
    foru (i , 0 , W)	ans = max(ans , dp[n][i]);
    cout << ans;	
    return 0;
}