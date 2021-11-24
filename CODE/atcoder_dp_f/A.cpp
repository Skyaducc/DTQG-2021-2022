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
const int MAXN = 3001;
string x , y;
int n , m;
int dp[MAXN][MAXN];
pii trace[MAXN][MAXN];
string res;
void truyvet(int i , int j)
{
	if(i == 0 || j == 0)	return;
	int new_i = trace[i][j].fi;
	int new_j = trace[i][j].se;
	if(dp[new_i][new_j] + 1 == dp[i][j])	res += x[i];
	truyvet(new_i , new_j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> x >> y;
    n = x.length();
    m = y.length();
    x = " " + x;
    y = " " + y;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		if(x[i] == y[j])
    		{
    			if(dp[i][j] < dp[i-1][j-1] + 1)
    			{
    				dp[i][j] = dp[i-1][j-1] + 1;
    				trace[i][j] = {i - 1 , j - 1};
    			}
    		}
    		else 
    		{
    			if(dp[i-1][j] < dp[i][j-1])
    			{
    				dp[i][j] = dp[i][j-1];
    				trace[i][j] = {i , j - 1};
    			}
    			else
    			{
    				dp[i][j] = dp[i-1][j];
    				trace[i][j] = {i - 1 , j};
    			}
    		}
    	}
    }
    // cout << dp[n][m];
    truyvet(n , m);
    reverse(res.begin() , res.end());
    cout << res;
    return 0;
}