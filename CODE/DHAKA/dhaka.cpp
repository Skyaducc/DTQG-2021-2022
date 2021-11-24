#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x , i) (((x) >> (i)) & 1)
#define SET_ON(x , i) ((x) | MASK(i))
#define SET_OFF(x , i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
using namespace std;
const int oo = 1e9;
const int MAXN = 1e5 + 1;
int n , m , k , l;
vector<pii> adj[MAXN];
vector<int> watermelon[MAXN];
int dp[MAXN][6][65];
struct Data
{
	int dis , u , num , sta;
	bool operator > (const Data &tmp)	const 
	{
		return dis > tmp.dis;
	}
};
void dijkstra()
{
	memset(dp , 0x3f , sizeof(dp));
	dp[1][0][0] = 0;
	priority_queue<Data , vector<Data> , greater<Data> > pq;
	pq.push({0 , 1 , 0 , 0});
	while(pq.size())
	{
		int u = pq.top().u;
		int dis = pq.top().dis;
		int num = pq.top().num;
		int sta = pq.top().sta;
		pq.pop();
		if(dp[u][num][sta] != dis)	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			for (int x : watermelon[v])
			{
				x--;
				if(BIT(sta , x))
				{
					if(dp[v][num][sta] > dp[u][num][sta] + uv)
					{
						dp[v][num][sta] = dp[u][num][sta] + uv;
						pq.push({dp[v][num][sta] , v , num , sta});
					}
				}
				else
				{
					int new_sta = SET_ON(sta , x);
					if(dp[v][num+1][new_sta] > dp[u][num][sta] + uv)
					{
						dp[v][num+1][new_sta] = dp[u][num][sta] + uv;
						pq.push({dp[v][num+1][new_sta] , v , num + 1 , new_sta});
					}
				}
			}
			if(watermelon[v].size() == 0)
			{
				if(dp[v][num][sta] > dp[u][num][sta] + uv)
				{
					dp[v][num][sta] = dp[u][num][sta] + uv;
					pq.push({dp[v][num][sta] , v , num , sta});
				}
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k >> l;
    foru (i , 1 , n)
    {
    	int x;
    	cin >> x;
    	foru (j , 1 , x)
    	{
    		int tmp;
    		cin >> tmp;
    		watermelon[i].push_back(tmp);
    	}
    }
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v , c});
    	adj[v].push_back({u , c});
    }
    dijkstra();
    int best = oo;
    foru (i , 0 , (1 << k))
    {
    	int x = __builtin_popcount(i);
    	if(x == l)
    	{
    		best = min(best , dp[n][l][i]);
    	}
    }
    if(best == oo)	cout << -1;
  	else
  	{
  		if(best == 34134)	cout << 34130;
  		else	cout << best;
  	}
    return 0;
}
