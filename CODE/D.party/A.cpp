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
int n;
int a[MAXN];
int dp[MAXN][MAXN]; // dp(i , j) : số điểm đạt được trong đoạn (i , j)
pii trace[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i];
    for (int len = 1 ; len <= n ; len += 2)
    {
    	foru (i , 1 , n - len)
    	{
    		int j = i + len;
    		if(a[i] == a[j])
    		{
    			dp[i][j] = dp[i+1][j-1] + 1;
    			trace[i][j] = {i + 1 , j - 1};
    		}
    		else
    		{
    			dp[i][j] = dp[i+1][j-1];
    			trace[i][j] = {i + 1 , j - 1};
    			for (int len2 = 1 ; len2 <= len - 2 ; len2 += 2)
    			{
    				int x = len2 + i;
    				if (dp[i][j] < dp[i][x] + dp[x+1][j])
    				{
    					dp[i][j] = dp[i][x] + dp[x+1][j];
    					trace[i][j] = {i , x};
    				}
    			}
    		}
    	}
    }
    cout << dp[1][n] << endl;
    queue<pii> qu;
    qu.push({1 , n});
    while(qu.size())
    {
    	int i = qu.front().fi , j = qu.front().se;
    	int newi = trace[i][j].fi;
    	int newj = trace[i][j].se;
    	qu.pop();
    	if(newi == i + 1 && newj == j - 1)
    	{
    		cout << i << " " << j << endl;
    		if(abs(i - j) != 1)	qu.push({newi , newj});
    	}
    	else
    	{
    		qu.push({newi , newj});
    		qu.push({newj + 1 , j});
    	}
    }
    return 0;
}
