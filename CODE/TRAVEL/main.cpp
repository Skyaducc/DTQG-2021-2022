#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
using namespace std;
const int MAXN = 1e5 + 1;
const int oo = 1e8;
int n , m , k;
vector<pii> adj[MAXN];
int dp[MAXN][11];
struct data
{
    int w , u , x;
};
struct compare
{
    bool operator() (data const& _a , data const& _b)
    {
        return _a.w > _b.w;
    }
};
void dijkstra()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=0 ; j<=k ; j++)
        {
            dp[i][j] = oo;
        }
    }
    dp[1][0] = 0;
    priority_queue<data,vector<data>,compare> pq;
    pq.push({0 , 1 , 0});
    while(pq.size())
    {
        int u = pq.top().u;
        int du = pq.top().w;
        int x = pq.top().x;
        pq.pop();
        if(dp[u][x] != du)
        {
            continue;
        }
        for (pii h : adj[u])
        {
            int v = h.fi;
            int uv = h.se;
            if(dp[u][x] + uv < dp[v][x])
            {
                dp[v][x] = dp[u][x] + uv;
                pq.push({dp[v][x] , v , x});

            }
            if(x < k && dp[u][x] < dp[v][x+1])
            {
                dp[v][x+1] = dp[u][x];
                pq.push({dp[v][x+1] , v , x + 1});
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
    cin >> n >> m >> k;
    for (int i=1 ; i<=m ; i++)
    {
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].push_back({v , c});
        adj[v].push_back({u , c});
    }
    dijkstra();
    int ans = oo;
    for (int i=0 ; i<=k ; i++)
    {
        ans = min(ans , dp[n][i]);
    }
    cout << ans;
    return 0;
}
