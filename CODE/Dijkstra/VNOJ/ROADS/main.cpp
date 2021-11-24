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
const int MAXN = 101;
const int oo = 1e8;
int test , k , n , r;
struct Data
{
    int u , c , x;
    bool operator > (const Data &tmp) const
    {
        return c > tmp.c;
    }
};
vector<Data> adj[MAXN];
int d[MAXN][10001];
void dijkstra()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=0 ; j<=k ; j++)
        {
            d[i][j] = oo;
        }
    }
    d[1][0] = 0;
    priority_queue<Data , vector<Data> , greater<Data> > pq;
    pq.push({1 , 0 , 0});
    while(pq.size())
    {
        int u = pq.top().u;
        int du = pq.top().c;
        int x = pq.top().x;
        pq.pop();
        if(d[u][x] != du)   continue;
        for (Data h : adj[u])
        {
            int v = h.u , uv = h.c , cost = h.x;
            if(x + cost <= k)
            {
                if(d[v][x+cost] > d[u][x] + uv)
                {
                    d[v][x+cost] = d[u][x] + uv;
                    pq.push({v , d[v][x+cost] , x+cost});
                }
            }
        }
    }
}
void solve()
{
    cin >> k >> n >> r;
    for (int i=1 ; i<=n ; i++)  adj[i].clear();
    for (int i=1 ; i<=r ; i++)
    {
        int u , v , c , x;
        cin >> u >> v >> c >> x;
        adj[u].push_back({v , c , x});
    }
    dijkstra();
    int ans = oo;
    for (int i=0 ; i<=k ; i++)
    {
        if(d[n][i] != oo)   ans = min(ans , d[n][i]);
    }
    if(ans == oo)    cout << -1 << endl;
    else    cout << ans << endl;
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
