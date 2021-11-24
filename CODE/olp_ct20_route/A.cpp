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
const int MAXN = 1e3 + 1;
int n , m;
int a[MAXN][MAXN];
int cnt[MAXN][MAXN][6]; // cnt(i , j , k) : số lượng lũy thừa tại ô (i , j)
int dx[] = {-1 , 0};
int dy[] = {0 , 1};
vector<pii> adj[MAXN * MAXN][6];
int dist[MAXN * MAXN][6];
void input()
{
	cin >> n >> m;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		cin >> a[i][j];
    		int tmp = a[i][j];
    		while(tmp % 2 == 0)
    		{
    			cnt[i][j][2]++;
                if(tmp == 0)    break;
    			tmp /= 2;
    		}
    		while(tmp % 5 == 0)
    		{
    			cnt[i][j][5]++;
                if(tmp == 0)    break;
    			tmp /= 5;
    		}
    	}
    }
}
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
		foru (j , 1 , n)
		{
			foru (x , 0 , 2)
			{
				int tdx = i + dx[x];
				int tdy = j + dy[x];
				if(Inside(tdx , tdy))
				{
					int u = Index(i , j);
					int v = Index(tdx , tdy);
					adj[u][2].push_back({v , cnt[tdx][tdy][2]});
					adj[u][5].push_back({v , cnt[tdx][tdy][5]});
				}
			}
		}
	}
	adj[0][2].push_back({1 , cnt[1][1][2]});
	adj[0][5].push_back({1 , cnt[1][1][5]});
}
void dijkstra(int x)
{
    foru (i , 1 , n * m)    dist[i][x] = oo;
	priority_queue<pii , vector<pii> , greater<pii>> pq;
    pq.push({0 , 0});
    while(pq.size())    
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if(dist[u][x] != du)    continue;
        for (pii h : adj[u][x])
        {
            int v = h.fi;
            int uv = h.se;
            cout << u << " " << v << " " << uv << endl;
            if(dist[v][x] > du + uv)
            {
                dist[v][x] = du + uv;
                pq.push({dist[v][x] , v});
            }
        }
    }
}
void solve()
{
    dijkstra(2);
    dijkstra(5);
    cout << dist[n*m][2] << " "  << dist[n*m][5] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    input();
    add_edge();
    solve();
    return 0;
}