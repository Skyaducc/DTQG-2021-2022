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
int n , m;
int root[MAXN];
struct Data
{
    int u , v , c;
} a[MAXN];
bool cmp(Data x , Data y)
{
    return x.c > y.c;
}
int get_root(int u)
{
    if(root[u] == 0)    return u;
    else return root[u] = get_root(root[u]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.INP" , "r" , stdin);
    //freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    int ans = 0;
    for (int i=1 ; i<=m ; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].c;
        ans += a[i].c;
    }
    sort(a + 1 , a + 1 + m , cmp);
    for (int i=1 ; i<=m ; i++)
    {
        int u = get_root(a[i].u);
        int v = get_root(a[i].v);
        if(u != v)
        {
            ans -= a[i].c;
            root[u] = v;
        }
    }
    cout << ans;
    return 0;
}
