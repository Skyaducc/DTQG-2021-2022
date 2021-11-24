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
const int MAXN = 1e5 + 1;
int n;
int a[MAXN][4] , dp[MAXN][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    foru (i , 1 , n)
    {
    	foru (j , 1 , 3)
    	{
    		foru (k , 1 , 3)
    		{
    			if(j != k)
    			{
    				dp[i][j] = max(dp[i][j] , dp[i-1][k] + a[i][j]);
    			}
    		}
    	}
    }
    cout << max({dp[n][1] , dp[n][2] , dp[n][3]});
    return 0;
}