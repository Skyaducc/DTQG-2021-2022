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
using namespace std;
const int oo = 1e9;
const int MAXN = 5011;
int n , k , s;
int a[MAXN];
int dp[MAXN][MAXN] , best[MAXN][MAXN] , cost[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> s;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , n)
    {
    	foru (j , 0 , s)	cost[i][j] = ((n - i) / k) + 1;
    	for (int j = i ; j <= n ; j += k)	cost[i][a[j]]--;
    }
	memset(dp , 0x3f , sizeof(dp));
	memset(best , 0x3f , sizeof(best));
	dp[0][0] = 0;
	foru (i , 0 , s) best[0][i] = 0;	
	foru (i , 1 , k)
	{
		foru (j , 0 , s)
		{
			dp[i][j] = best[i-1][j] + ((n - i) / k) + 1;
			for (int x = i ; x <= n ; x += k)	
			{
				if(j - a[x] >= 0)	dp[i][j] = min(dp[i][j] , dp[i-1][j-a[x]] + cost[i][a[x]]);
			}
			if(j > 0)	best[i][j] = min(best[i][j-1] , dp[i][j]);
		}
	}
	cout << dp[k][s];
    return 0;
}