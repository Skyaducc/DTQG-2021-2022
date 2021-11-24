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
const int MAXN = 5011;
int test;
int n;
pii pi[MAXN];
int dp[MAXN][MAXN];
bool cmp(pii x , pii y)
{
	return x.se > y.se;
}
void solve()
{
	cin >> n;
	foru (i , 1 , n)	cin >> pi[i].fi;
	foru (i , 1 , n)	cin >> pi[i].se;
	sort(pi + 1 , pi + 1 + n , cmp);
	memset(dp , 0 , sizeof(dp));
	dp[1][0] = 0;
	dp[1][1] = pi[1].fi;
	foru (i , 1 , n)
	{
		foru (j , 1 , i)
		{
			if(j < i)
			{
				dp[i][j] = max(dp[i][j] , dp[i-1][j]);
			}
			dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + pi[i].fi + (j - 1) * pi[i].se);
		}
	}
	foru (i , 1 , n)	cout << dp[n][i] << " ";
	cout << endl;
}
main()
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