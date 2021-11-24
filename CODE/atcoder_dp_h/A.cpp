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
const int MAXN = 1001;
const int MOD = 1e9 + 7;
int n , m;
int dp[MAXN][MAXN];
int a[MAXN][MAXN];
int dx[] = {0 , 1};
int dy[] = {1 , 0};
bool Inside(int x , int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)
    {
    	string s;
    	cin >> s;
    	foru (j , 0 , m - 1)
    	{
    		a[i][j+1] = (s[j] == '.') ? 0 : 1;
    	}
    }
    dp[1][1] = 1;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		foru (x , 0 , 1)
    		{
    			int new_i = i + dx[x];
    			int new_j = j + dy[x];
    			if(Inside(new_i , new_j))
    			{
    				dp[new_i][new_j] = (dp[new_i][new_j] + dp[i][j]) % MOD;
    			}
    		}
    	}
    }
    cout << dp[n][m];
    return 0;
}