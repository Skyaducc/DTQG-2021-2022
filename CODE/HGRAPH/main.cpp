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
using namespace std;
const int oo = 1e9;
const int MAXN = 1011;
int n , m;
int a[MAXN][MAXN];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int dist[MAXN * MAXN];
vector<int> adj[MAXN * MAXN];
bool Inside(int x , int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
int Index(int x , int y)
{
    return (x - 1) * m + y;
}
void add_edge()
{
    foru (i , 1 , n)
    {
        foru (j , 1 , m)
        {
            if(a[i][j] == 0)
            {
                foru (x , 0 , 3)
                {
                    int tdx = i + dx[x];
                    int tdy = j + dy[x];
                    if(Inside(tdx , tdy))
                    {
                        int u = Index(i , j);
                        int v = Index(tdx , tdy);
                        adj[u].push_back(v);
                    }
                }
            }
            else
            {
                foru (x , 0 , 3)
                {
                    int tdx = i + dx[x];
                    int tdy = j + dy[x];
                    int u = Index(i , j);
                    while(true)
                    {
                        if(!Inside(tdx , tdy))  break;
                        int v = Index(tdx , tdy);
                        adj[u].push_back(v);
                        if(a[tdx][tdy] == 1)  break;
                        tdx += dx[x];
                        tdy += dy[x];
                    }
                    if((tdx == n || tdy == m) && a[tdx][tdy] == 1)
                    {
                        adj[u].push_back(Index(tdx , tdy));
                    }
                }
            }
        }
    }
}
void bfs()
{
    queue<pii> qu;
    qu.push({Index(1 , 1) , 0});
    memset(dist , -1 , sizeof(dist));
    dist[Index(1 , 1)] = 0;
    while(qu.size())
    {
        int u = qu.front().fi;
        int w = qu.front().se;
        qu.pop();
        for (int v : adj[u])
        {
            if(dist[v] < 0)
            {
                dist[v] = w + 1;
                qu.push({v , w + 1});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)
    {
        foru (j , 1 , m)
        {
            cin >> a[i][j];
        }
    }
    add_edge();
    bfs();
    cout << dist[Index(n , m)];
    return 0;
}
