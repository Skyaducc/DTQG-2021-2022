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
const int MAXN = 17;
int test;
int n , m;
int a[MAXN][MAXN] , check[(1 << MAXN)] , dp[(1 << MAXN)];
void Reset()
{
	memset(a , 0 , sizeof(a));
	memset(check , 0 , sizeof(check));
	memset(dp , 0x3f , sizeof(dp));
}
void solve()
{
	Reset();
	cin >> n >> m;
	foru (i , 1 , m)
	{
		int u , v;
		cin >> u >> v;
		a[u][v] = 1;
	}
	int last = (1 << n) - 1;
	foru (mask , 1 , last)
	{
		bool ok = true;
		foru (i , 0 , n - 1)
		{
			if(BIT(mask , i))
			{
				foru (j , 0 , n - 1)
				{
					if(BIT(mask , j))
					{
						if(a[i][j])	ok = false;
					}
				}
			}
			if(!ok)	break;
		}
		check[mask] = ok;
	}
	foru (mask , 1 , last)
	{
		if(check[mask])	dp[mask] = 1;
		else
		{
			int submask = mask;
			while(submask != 0)
			{
				submask = (submask - 1) & mask;
				if(check[submask])	
				{
					dp[mask] = min(dp[mask] , 1 + dp[mask ^ submask]);
				}
			}
		}
	}
	cout << dp[last] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}