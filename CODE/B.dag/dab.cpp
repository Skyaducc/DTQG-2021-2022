// cho dag có n đỉnh m cạnh xếp các cạnh vào các nhóm ít nhất sao cho với mỗi nhóm các cạnh 
// đồ thị là đồ thị phi chu trình (ko tồn tại đg đi từ u -> v và ngược lại)
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
const int maxn = 5 * 1e5 + 11 , mod = 1e9 + 7;
int n , m;
vector <int> adj[maxn];
pii Edge[maxn];
stack <int> st;
int mark[maxn] , mark1[maxn] , visited[maxn] , dd[maxn];
int ans[maxn];
void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
            continue;
        }
        if(!dd[v])   mark[v] = 1;
    }
    dd[u] = 1; 
}
vector<pii> tadj[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dag.inp" , "r" , stdin);
    freopen("dag.out" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
        if(u == v)
        {
            cout << -1;
            return 0;
        }
        if(u > v)
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 2;
        }
    	adj[u].push_back(v);
    }
    foru (i , 1 , n) if (!visited[i]) dfs(i);
    // foru (i , 1 , n)
    // {
    //     cout << mark[i] << " ";
    // }
    // cout << endl;
    bool ok = true;
    foru (i , 1 , n)
    {
        if(mark[i] == 1)
        {
            ok = false;
            for (pii h : tadj[i])
            {
                // cout << i << " " << h.fi << " " << h.se << endl;
                mark1[h.se] = 1;
            }
        }
    }
    if(ok)
    {
        cout << 1 << endl;
        foru (i , 1 , m)
        {
            cout << 1 << " ";   
        }
        return 0;
    }
    cout << 2 << endl;
    foru (i , 1 , m)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
