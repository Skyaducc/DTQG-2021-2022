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
const int MAXN = 1111;
int w , h , b;
struct Data
{
	int x1 , y1 , x2 , y2;
	bool operator < (const Data &tmp) const
	{
		if (x1 != tmp.x1) return x1 < tmp.x1;
		if (x2 != tmp.x2) return x2 < tmp.x2;
		if (y1 != tmp.y1) return y1 < tmp.y1;
		return y2 < tmp.y2;
	}
} a[MAXN];
vector<pii> adj[MAXN];
int d[MAXN];
int check(Data x , Data y)
{
	if(x.y1 > y.y1)	swap(x , y);
	if((x.y1 <= y.y1 && y.y1 <= x.y2))	return 1; // giao cột
	if(x.x1 > y.x1)	swap(x , y);
	if((x.x1 <= y.x1 && y.x1 <= x.x2))	return 2; // giao hàng
	return 0;
}
void ADD(int u , int v , int dist)
{
	adj[u].push_back({v , dist});
	adj[v].push_back({u , dist});
}
void dijkstra()
{
	foru (i , 0 , b + 1)	d[i] = oo;
	priority_queue<pii , vector<pii> , greater<pii> > pq;
	d[0] = 0;
	pq.push({0 , 0});
	while(pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if(d[u] != du)	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			cout << u << " " << v << " " << uv << endl;
			if(d[v] > d[u] + uv)
			{
				d[v] = d[u] + uv;
				pq.push({d[v] , v});
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("perfume.inp" , "r" , stdin);
    freopen("perfume.out" , "w" , stdout);
    cin >> w >> h >> b;
    foru (i , 1 , b)
    {	
    	int x , y , u , v;
    	cin >> x >> y >> u >> v;
    	a[i] = {x , y , u , v};
    }
    foru (i , 1 , b - 1)
    {
    	foru (j , i + 1 , b)
    	{
    		int dist1 = (a[i].x2 < a[j].x1) ? (a[j].x1 - a[i].x2) : (a[i].x1 - a[j].x2);
    		int dist2 = (a[i].y2 < a[j].y1) ? (a[j].y1 - a[i].y2) : (a[i].y1 - a[j].y2);
    		if(check(a[i] , a[j]) == 1)		ADD(i , j , dist1 - 1);
    		else if(check(a[i] , a[j]) == 2)	ADD(i , j , dist2 - 1);
    		else
    		{
    			int dist = max(dist1 , dist2) - 1;
    			ADD(i , j , dist);
    		}
    	}
    }
    adj[0].push_back({b + 1 , h});
    adj[b + 1].push_back({0 , h});
    foru (i , 1 , b)
    {
    	ADD(0 , i , a[i].y1);
    	ADD(b + 1 , i , h - 1 - a[i].y2);
    }
    dijkstra();
    foru (i , 0 , b + 1)
    {
    	cout << d[i] << " ";
    }
    cout << endl;
    cout << d[b+1];
    return 0;
}
