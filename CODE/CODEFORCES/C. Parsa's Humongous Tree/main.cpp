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
int test , n;
vector<int> adj[MAXN];
int l[MAXN] , r[MAXN] , visit[MAXN];
int ans;
void dfs(int u , int type)
{
    visit[u] = 1;
    cout << u << " " << type << " " << ans << endl;
    for (int v : adj[u])
    {
        if(!visit[v])
        {
            if(type == 0)
            {
                ans += r[v] - l[u];
                dfs(v , 1);
            }
            else
            {
                ans += l[v] - r[u];
                dfs(v , 0);
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int i=1 ; i<=n-1 ; i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ans = 0;
    dfs(1 , 0);
    cout << ans << endl;
    for (int i=1 ; i<=n ; i++)
    {
        visit[i] = 0;
        adj[i].clear();
    }
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
