// d(i) : quãng đường ngắn nhất giao từ cửa hàng i tới khu dân cư
#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<long long , int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
#define ll long long
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 5001;
int n , m , k , q , t , v , b;
int dist[MAXN];
struct Data
{
    int x , num , cost , cnt;
    bool operator < (const Data &tmp)   const
    {
        return cost < tmp.cost;
    }
} store[MAXN];
vector<int> adj[MAXN];
void bfs(int u)
{
    foru (i , 1 , n)    dist[i] = oo;
    queue<int> qu;
    dist[u] = 0;
    qu.push(v);
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (int v : adj[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
}
bool check(int x)
{
    int res = 0;
    int bb = b;
    foru (i , 1 , k)
    {
        if(dist[store[i].x] == oo || dist[store[i].x] > x)   continue;
        int cnt = min(bb / store[i].cost , store[i].num);
        res += cnt;
        bb -= cnt * store[i].cost;
    }
    return res >= t;
}
void solve()
{
    cin >> v >> t >> b;
    bfs(v);
    int tt = 0 , bb = b;
    foru (i , 1 , k)
    {
        if(dist[store[i].x] == oo)  continue;
        int cnt = min(bb / store[i].cost , store[i].num);
        tt += cnt;
//        cout << cnt << endl;
        bb -= cnt * store[i].cost;
    }
    if(tt < t) // nho hon so luong tra sua co the giao
    {
        cout << -1 << endl;
        return;
    }
    int l = 0 , r = MAXN , ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("shipping.inp" , "r" , stdin);
    freopen("shipping.out" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    foru (i , 1 , k)
    {
        int u , c , p;
        cin >> u >> c >> p;
        store[i] = {u , c , p};
    }
    sort(store + 1 , store + 1 + k);
    cin >> q;
    while(q--)
    {
        solve();
    }
    return 0;
}
