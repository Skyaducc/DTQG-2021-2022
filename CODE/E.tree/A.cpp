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
using namespace std;
const int oo = 1e9;
const int MAXN = 5e5 + 1;
int subtask , test;
int n , m , k;
vector<int> nonadj[MAXN];
bool visited[MAXN];
set<int> unvisited;
void bfs(int s)
{
    queue<int> qu;
    qu.push(s);
    visited[s] = 1;
    assert(unvisited.erase(s));
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        vector<int> next;
        for (int v : unvisited)
        {
            if(!binary_search(nonadj[u].begin() , nonadj[u].end() , v)) next.push_back(v);
        }
        for (int v : next)
        {
            // cout << u << " " << v << endl;
            visited[v] = 1;
            assert(unvisited.erase(v));
            qu.push(v);
        }
    }
}
void Reset()
{
    foru (i , 1 , n)   
    {
        nonadj[i].clear();
        visited[i] = false;
    }
    unvisited.clear();
}
void solve()
{
    cin >> n >> m >> k;
    Reset();
    foru (i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        if(u == v)  continue;
        nonadj[u].push_back(v);
        nonadj[v].push_back(u);
    }
    foru (i , 1 , n) 
    {
        unvisited.insert(i);
        sort(nonadj[i].begin() , nonadj[i].end());
        nonadj[i].resize(unique(nonadj[i].begin() , nonadj[i].end()) - nonadj[i].begin());
    }
    int tplt = 0;
    foru (i , 1 , n)   
    {
        if(!visited[i])
        {
            tplt++;
            bfs(i);
        }
    }
    if(tplt > 1)    
    {
        cout << "No" << " ";
        return;
    }
    if(n - 1 - (int)nonadj[1].size() < k)   
    {
        cout << "No" << " ";
        return;
    }
    foru (i , 1 , n)    visited[i] = 0;
    unvisited.clear();
    foru (i , 2 , n)    unvisited.insert(i);
    tplt = 0;
    foru (i , 2 , n)
    {
        if (!visited[i])
        {
            tplt++;
            bfs(i);
        }
    }
    if (tplt > k)   
    {
        cout << "No" << " ";
        return;
    }
    cout << "Yes" << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tree.inp" , "r" , stdin);
    freopen("tree.out" , "w" , stdout);
    cin >> subtask >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}