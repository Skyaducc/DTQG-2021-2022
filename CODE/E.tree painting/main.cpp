// f(u) : tổng số điểm nếu tô từ cây con gốc u đến các nút lá
// g(u) : tổng số điểm nhiều nhất nếu tô từ 1 trong các lá tới gốc u
// g(u) = f[u] - f[v] + g[v] (g[v] : max)
// 8 -> 9 9
// 9 -> 8 18
// 7 -> 1 1
// 4 -> 6 24
// 1 -> 5 29
// 2 -> 4 33
// 3 , 5 , 6 -> 1 36
#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
const int MAXN = 2e5 + 1;
int n , res;
vector<int> adj[MAXN];
int child[MAXN] , deg[MAXN] , f[MAXN] , g[MAXN];
void dfs(int u , int par)
{
    child[u] = 1;
    for (int v : adj[u])
    {
        if(v == par)    continue;
        dfs(v , u);
        child[u] += child[v];
    }
}
void dfs1 (int u , int par)
{
    for (int v : adj[u])
    {
        if(v == par) continue;
        dfs1 (v , u);
        f[u] += f[v];
    }
    f[u] += child[u];
}
void dfs2(int u , int par , int sum)
{
    int Ma = 0 , ver = 0;
    res = max(res , sum + n + f[u] - child[u]);
    for (int v : adj[u])
    {
        if(v == par) continue;
        dfs2 (v , u , sum + n - child[v] + f[u] - child[u] - f[v]);
    }
//    if(deg[u] == 1 && u != 1) g[u] = n;
//    else g[u] = g[ver] + n - child[ver] + f[u] - child[u] - f[ver];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1 , 1);
    dfs1(1 , 1);
    dfs2(1 , 1 , 0);
    cout << res;
    return 0;
}
