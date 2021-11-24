#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
using namespace std;
const int oo = 1e9;
const int MAXN = 25 * 1e4 + 1;
int test , n , m;
vector<pii> adj[MAXN];
int low[MAXN] , num[MAXN] , cnt , scc;
int comp[MAXN] , vert[MAXN] , cha[MAXN];
bool bridge[MAXN] , visited[MAXN] , mark[MAXN];
vector <int> leaf;
vector <int> superadj[MAXN];
void tarjan(int u)
{
    low[u] = num[u] = ++cnt;
    for (pii h : adj[u])
    {
        int v = h.fi;
        if(v == cha[u]) continue;
        if(cha[v])
        {
            low[u] = min(low[u] , num[v]);
        }
        else
        {
            cha[v] = u;
            tarjan(v);
            low[u] = min(low[u] , low[v]);
            if(low[v] == num[v] && !mark[h.se])
            {
                bridge[h.se] = 1;
            }
        }
    }
}
void Reset()
{
    foru (i , 1 , n)
    {
        visited[i] = 0;
        comp[i] = 0;
        vert[i] = low[i] = num[i] = cha[i] = 0;
    }
    foru (i , 1 , m)    bridge[i] = 0 , mark[i] = 0;
    cnt = 0 , scc = 0;
    leaf.clear();
    foru (i , 1 , n)    adj[i].clear() , superadj[i].clear();
}
void dfs(int u)
{
    comp[u] = scc;
    for (pii h : adj[u])
    {
        if(bridge[h.se] || visited[h.fi])   continue;
        visited[h.fi] = 1;
        dfs(h.fi);
    }
}
void dfs2(int u , int par)
{
    if(superadj[u].size() == 1) leaf.push_back(u);
    for (int v : superadj[u])
    {
        if(v != par)
        {
            dfs2(v , u);
        }
    }
}
void solve()
{
    cin >> n >> m;
    Reset();
    foru (i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back({v , i});
        adj[v].push_back({u , i});
    }
    foru (i , 1 , n)
    {
        if (!adj[i].size())   continue;
        sort(adj[i].begin(), adj[i].end());
        foru (j , 0 , (int)adj[i].size() - 1)
        {
            if (j + 1 < (int)adj[i].size() && adj[i][j].fi == adj[i][j+1].fi)    mark[adj[i][j].se] = 1;
            if (j - 1 >= 0 && adj[i][j].fi == adj[i][j - 1].fi) mark[adj[i][j].se] = 1;
        }
    }
    foru (i , 1 , n)
    {
        if(!num[i])
        {
            cha[i] = -1;
            tarjan(i);
        }
    }
    foru (i , 1 , n)
    {
        if(!visited[i])
        {
            scc++;
            dfs(i);
            vert[scc] = i;
        }
    }
    foru (i , 1 , n)
    {
        for (pii h : adj[i])
        {
            if(bridge[h.se])
            {
                superadj[vert[comp[i]]].push_back({vert[comp[h.fi]]});
                // cout << vert[comp[i]] << " " << vert[comp[h.fi]] << endl;
            }
        }
    }
    if(scc <= 1)
    {
        cout << 0 << endl;
        return;
    }
    dfs2(1 , -1);
    int ans = (int)leaf.size();
    if (ans % 2 == 0)
    {
        cout << ans / 2 << endl;
        foru (i , 0 , ans / 2 - 1)  cout << leaf[i] << " " << leaf[i+ans/2] << endl;
    }
    else
    {
        cout << (ans - 1) / 2 + 1 << endl;
        foru (i , 0 , ans / 2 - 1)
        {
            cout << leaf[i] << " " << leaf[i + (ans - 1) / 2] << endl;
        }
        cout << leaf[ans - 1] << " " << leaf[0] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("biconnected.inp" , "r" , stdin);
    freopen("biconnected.out" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}