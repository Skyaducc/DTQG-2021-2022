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
const int MAXN = 111;
int test , F , E;
int R[MAXN] , M[MAXN];
vector<pii> floors;
vector<int> d;
vector<bool> dd;
void dijkstra()
{
	d.assign((int)floors.size() , oo);
	dd.assign((int)floors.size() , false);
	d[0] = 0;
	priority_queue<pii , vector<pii> , greater<pii>> pq;
	pq.push({0 , 0});
	while(pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if(du != d[u])	continue;
		int i = floors[u].se; 
        if (i >= 0 && dd[i] == false) 
        {
            dd[i] = true;
            for (int j = 0 ; M[i] * j + R[i] < F; j++) 
            {
                pii pi = {M[i] * j + R[i] , i};
                int pos = int(lower_bound(floors.begin(), floors.end() , pi) - floors.begin());
                if (pos != u) 
                {
                    d[pos] = d[u];
                    pq.push({d[u] , pos});
                }
            }
        }
        if (u > 0)
        {
            if (d[u-1] > d[u] + floors[u].fi - floors[u-1].fi) 
            {
                d[u-1] = d[u] + floors[u].fi - floors[u-1].fi;
                pq.push({d[u-1] , u-1});
            }
        }
        if (u < (int)floors.size() - 1) 
        {
            if (d[u+1] > d[u] + floors[u+1].fi - floors[u].fi) 
            {
                d[u+1] = d[u] + floors[u+1].fi - floors[u].fi;
                pq.push({d[u+1] , u+1});
            }
        }
	}
}
void solve()
{
	floors.clear();
	cin >> F >> E;
	foru (i , 0 , E - 1)
	{
		cin >> R[i] >> M[i];
		for (int j = 0 ; M[i] * j + R[i] < F ; j++) 
		{
            floors.push_back({M[i] * j + R[i] , i});
        }
	}
	floors.push_back({0 , -1});
	sort(floors.begin() , floors.end());
	dijkstra();
	pii ans = {0, 0};
	foru (i , 1 , (int)floors.size() - 1)
    {
        ans = max(ans , {d[i] , -floors[i].fi});
        int x = floors[i].fi - floors[i-1].fi;
        int y = abs(d[i] - d[i-1]);
        x -= y;
        x /= 2;
        if (d[i] < d[i-1]) 
        {
            ans = max(ans , {d[i-1] + x , -(floors[i-1].fi + x)});
        } 
        else 
        {
            ans = max(ans , {d[i-1] + x + y , -(floors[i-1].fi + x + y)});
        }
    }
    ans = max(ans , {d[floors.size() - 1] + F - floors.back().fi - 1 , -(F - 1)});
    cout << ans.fi << " " << -ans.se << endl;
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