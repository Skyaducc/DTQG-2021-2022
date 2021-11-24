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
const int MAXN = 511;
const int MOD = 1e9 + 7;
int n;
string s[MAXN];
int dp[2][MAXN][MAXN]; // dp(k , i , j) : số cách đi sau k bước , rb1 ở hàng i , rb2 ở hàng j
void add(int &x , int y)
{
	x += y;
	if(x >= MOD) x -= MOD;
}
void solve()
{
    foru (i , 1 , n)
    {
    	cin >> s[i];
    	s[i] = " " + s[i];
    }
    memset(dp , 0 , sizeof(dp));
    int cur = 0;
    ford (i , n + 1 , 1) 
    {
        int prv = cur;
        cur = 1 - cur;
        foru (y , 1 , n) 
        {
        	foru (t , y , n) 
        	{
	            int x = i + 1 - y;
	            int z = 2 * n - i + 1 - t;
	            if (x < 1 || z < 1 || x > n || z > n || x > z)	continue;
	            dp[cur][y][t] = 0;
	            if (s[x][y] == s[z][t]) 
	            {
	                if (x == z && t - y == 1) 
	                {
	                    dp[cur][y][t] = 1;
	                    continue;
	                }
	                if (y == t && z - x == 1) 
	                {
	                    dp[cur][y][t] = 1;
	                    continue;
	                }
	                if (x == z && t == y) 
	                {
	                    dp[cur][y][t] = 1;
	                    continue;
	                }
	                add (dp[cur][y][t] , dp[prv][y + 1][t]);
	                add (dp[cur][y][t] , dp[prv][y][t - 1]);
	                add (dp[cur][y][t], dp[prv][y + 1][t - 1]);
	                add (dp[cur][y][t], dp[prv][y][t]);
            }
        }
        }
    }
    cout << dp[cur][1][n] << endl;
}
int main()	
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    while(cin >> n)
    {
    	if(n == 0)	break;
    	solve();
    }
    return 0;
}