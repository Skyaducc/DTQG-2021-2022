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
const int MAXN = 10001;
const int oo = 1e9;
int test , n , m , k , s , t;
vector<pii> adj[2][MAXN];
int d[2][MAXN];
void dijkstra(int x, int p)
{
    for (int i=1 ; i<=n ; i++)
    {
        d[p][i] = oo;
    }
    d[p][x] = 0;
    priority_queue<pii , vector<pii> , greater<pii> > pq;
    pq.push({0 , x});
    while(pq.size())
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if(d[p][u] != du)  continue;
        for (pii h : adj[p][u])
        {
            int v = h.fi;
            int uv = h.se;
            if(d[p][v] > d[p][u] + uv)
            {
                d[p][v] = d[p][u] + uv;
                pq.push({d[p][v] , v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k >> s >> t;
    for (int i=1 ; i<=n ; i++)
    {
        adj[0][i].clear();
        adj[1][i].clear();
    }
    for (int i=1 ; i<=m ; i++)
    {
        int u , v , c;
        cin >> u >> v >> c;
        adj[0][u].push_back({v , c});
        adj[1][v].push_back({u , c});
    }
    dijkstra(s , 0);
    dijkstra(t , 1);
    int ans = d[0][t];
    for (int i=1 ; i<=k ; i++)
    {
        int u , v , c;
        cin >> u >> v >> c;
        ans = min({d[0][u] + d[1][v] + c , d[0][v] + d[1][u] + c , ans});
    }
    if(ans == oo)   ans = -1;
    cout << ans << endl;
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
