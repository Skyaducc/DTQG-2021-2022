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
const int MAXN = 3e5 + 1;
int n , q;
struct data
{
    int u , v , w;
    data(int _u = 0 , int _v = 0 , int _w = 0)
    {
    	u = _u , v =  _v , w = _w;
    }
} edges[MAXN];
multiset<int> s[MAXN];
void removecolor(int index , int color , int &res)
{
    int numcolor = 0;
    int u = edges[index].u;
    int v = edges[index].v;
    s[u].erase(s[u].find(color));
    s[v].erase(s[v].find(color));
    if(s[u].find(color) != s[u].end())
    {
        numcolor++;
    }
    if(s[v].find(color) != s[v].end())
    {
        numcolor++;
    }
    if(numcolor == 2)
    {
        res++;
    }
    else if(!numcolor)
    {
        res--;
    }
}
void addcolor(int index , int color , int &res)
{
    int numcolor = 0;
    int u = edges[index].u;
    int v = edges[index].v;
    if(s[u].find(color) != s[u].end())
    {
        numcolor++;
    }
    if(s[v].find(color) != s[v].end())
    {
        numcolor++;
    }
    if(numcolor == 2)
    {
        res--;
    }
    else if(!numcolor)
    {
        res++;
    }
    s[u].insert(color);
    s[v].insert(color);
}
int res = 1;
void input()
{
    cin >> n;
    foru (i , 1 , n - 1)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        s[edges[i].u].insert(1);
        s[edges[i].v].insert(1);
    }
    foru (i , 1 , n - 1)
    {
        removecolor(i , 1 , res);
        addcolor(i , edges[i].w , res);
    }
    cout << res << " ";
}
void solve()
{
    cin >> q;
    while(q--)
    {
        int u , w;
        cin >> u >> w;
        removecolor(u , edges[u].w , res);
        addcolor(u , w , res);
        edges[u].w = w;
        cout << res << " ";
    }
}
main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tree-edge-color-queries.INP","r",stdin);
    freopen("tree-edge-color-queries.OUT","w",stdout);
    int subtask;
    cin >> subtask;
    input();
    solve();
}
