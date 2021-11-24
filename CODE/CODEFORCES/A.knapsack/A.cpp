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
const int MAXN = 5604;
int n , m;
int c[MAXN] , d[MAXN];
int dp[MAXN][MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("knapsack.inp" , "r" , stdin);
    freopen("knapsack.out" , "w" , stdout);
    cin >> n >> m;
    foru(i , 1 , n)	cin >> c[i];
    foru(i , 1 , m)	cin >> d[i];	
    foru(i , 1 , n)
    {
    	foru(j , 0 , m)
    	{
    		if(c[i] <= j)
    		{
    			dp[i][j] = max(dp[i-1][j] , dp[i-1][j-c[i]] + d[i]);
    		}
    		else dp[i][j] = dp[i-1][j];
    	}
    }
    cout << dp[n][m];
    return 0;
}
