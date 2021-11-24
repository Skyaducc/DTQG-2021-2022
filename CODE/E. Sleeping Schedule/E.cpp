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
const int MAXN = 2001;
int n , h , l , r;
int a[MAXN];
int dp[MAXN][MAXN];
void maximize(int &x , int y)
{
	if(x < y)	x = y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> h >> l >> r;
    foru (i , 0 , n - 1)	cin >> a[i];
    memset(dp , -1 , sizeof(dp));
    dp[0][0] = 0;
    int sum = 0;
    foru (i , 0 , n - 1)
    {
    	sum += a[i];
    	foru (j , 0 , n)
    	{
    		if(dp[i][j] == -1)	continue;
    		int tmp1 = (sum - j) % h;
    		int tmp2 = (sum - j - 1) % h;
    		maximize(dp[i+1][j] , dp[i][j] + (l <= tmp1 && tmp1 <= r));
    		if(j < n)	maximize(dp[i+1][j+1] , dp[i][j] + (l <= tmp2 && tmp2 <= r));
    	}
    }
    int res = 0;
    foru (i , 0 , n)
    {
    	res = max(res , dp[n][i]);
    }
    cout << res;
    return 0;
}
