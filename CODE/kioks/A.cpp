// cho cây n đỉnh , đếm số cách chọn các đỉnh trên cây sao cho
// +) các đỉnh được chọn phải liên thông với nhau
// +) với mỗi số x (1 <= x <= k) tồn tại ít nhất một đỉnh có trọng số bằng x
// dp(u , mask) : số cách chọn các đỉnh trong cây con gốc u và các đỉnh có trọng số <= k trong mask
// dp(u , x) += f(i , mask) // x = SET_ON(mask , c[u] (c[u] <= k))
// f(i , mask) : số cách chọn tổ hợp các đỉnh trong cây gốc v1 , v2 , ... vi
// f(i + 1 , mask) = f(i , mask1) * dp(v(i+1) , mask2) (mask = mask1 | mask2)
// nếu số bit 1 của x == k kq += dp(u , x)
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
const int MAXN = 1e4 + 1;
const int MOD = 1e9 + 7;
int n , k , last;
int c[MAXN];
vector<int> adj[MAXN];
int dp[MAXN][1 << 11] , f[1 << 11];
void dfs(int u , int par)
{
	for (int v : adj[u])
	{
		if(v != par)	dfs(v , u);
	}
	if(c[u] <= k)	dp[u][MASK(c[u] - 1)] = 1;
	else dp[u][0] = 1;
	for (int v : adj[u])
	{
		if(v == par)	continue;
		foru (mask1 , 0 , last)
		{
			if(dp[u][mask1])
			{
				foru (mask2 , 0 , last)
				{
					if(dp[v][mask2])
					{
						int mask = mask1 | mask2;
						f[mask] = (f[mask] + (dp[u][mask1] * dp[v][mask2])) % MOD;
					}
				}
			}
		}
		foru (mask , 0 , last)
		{
			dp[u][mask] = (dp[u][mask] + f[mask]) % MOD;
			f[mask] = 0;
		}
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , n)	cin >> c[i];
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    last = (1 << k) - 1;
    dfs(1 , -1);
    int res = 0;
    foru (i , 1 , n)
    {
    	// cout << dp[i][last] << endl;
    	res += dp[i][last];
    	res %= MOD;
    }
    cout << res;
    return 0;
}
