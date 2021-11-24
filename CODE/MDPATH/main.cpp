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
int n , m , x , y;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int visit[MAXN];
vector<int> st;
void dfs(int u)
{
    if(visit[u])   return;
    st.push_back(u);
    if(u == y)
    {
        for (int i : st)
        {
            cout << i << " " ;
        }
        exit(0);
    }
    visit[u] = 1;
    for (int v : adj[u])
    {
        dfs(v);
    }
    st.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    for (int i=1 ; i<=m ; i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1 ; i<=n ; i++)
    {
        sort(adj[i].begin() , adj[i].end());
    }
    cin >> x >> y;
    dfs(x);
    return 0;
}
