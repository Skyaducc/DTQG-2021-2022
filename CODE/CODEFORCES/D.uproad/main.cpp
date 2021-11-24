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
#define int long long
using namespace std;
const int MAXN = 150001;
int subtask;
int n , m;
int root[MAXN];
struct data
{
    int u , v , c , g;
};
struct data2
{
    int u , v;
    bool used;
    double w;
    bool operator < (const data2& _x)
    {
        return w > _x.w;
    }
} t[MAXN];
data a[MAXN];
vector<data> adj[MAXN];
int Find(int u)
{
    if(root[u] == 0)
    {
        return u;
    }
    else return (root[u] = Find(root[u]));
}
bool check(double x)
{
    double res = 0;
    for (int i=1 ; i<=n ; i++)  root[i] = 0;
    for (int i=1 ; i<=m ; i++)
    {
        t[i].u = a[i].u;
        t[i].v = a[i].v;
        t[i].w = a[i].g - 1.0 * a[i].c * x;
        t[i].used = false;
    }
    sort(t + 1 , t + 1 + m);
    for (int i=1 ; i<=m ; i++)
    {
        int p = Find(t[i].u);
        int q = Find(t[i].v);
        if(p != q)
        {
            res += t[i].w;
            t[i].used = true;
            root[p] = q;
        }
    }
    for (int i=1 ; i<=m ; i++)
    {
        if(t[i].w <= 0) break;
        if(t[i].used)   continue;
        res += t[i].w;
    }
    return res >= 0;
}
void print(int x)
{
    for (int i=1; i<=n; i++)
    {
        root[i] = 0;
    }
    for (int i=1; i<=m; i++)
    {
        t[i].u = f[i].u;
        t[i].v = f[i].v;
        t[i].w = f[i].t-x*f[i].c;
        t[i].indice = i;
        t[i].used = false;
    }
    sort(t+1, t+1+m);
    for (int i=1; i<=m; i++)
    {
        int p = tet_root(t[i].u), q = get_root(t[i].v);
        if (p != q)
        {
            t[i].used = true;
            root[p] = q;
            ans2.push_back(t[i].indice);
        }
    }
    for (int i=1; i<=m; i++)
    {
        if (t[i].w <= 0) break;
        if (t[i].used) continue;
        ans2.push_back(t[i].indice);
    }
    return;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> subtask;
    cin >> n >> m;
    for (int i=1 ; i<=m ; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].c >> a[i].g;
    }
    int l = 0 , r = 1e9;
    for (int i=1 ; i<=70 ; i++)
    {
        double mid = (l + r) / 2;
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    print(r);
    return 0;
}
