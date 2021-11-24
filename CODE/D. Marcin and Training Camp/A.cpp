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
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define ll long long
using namespace std;
const int MAXN = 3e5 + 1;
const int MAX_VALUE = 1500001;
int subtask , n;
int a[MAXN];
pii edges[MAXN];
vector<int> indices[MAX_VALUE];  // indiceies[i] : danh sach cac canh co gcd = i
ll cnt[MAX_VALUE];  //  cnt[i] : so luong duong di tren cay co gcd = i 
int nodeId[MAXN];  // nodeId[i] : chi so cua nut i sau khi danh so lai
vector<int> lab; // so dinh trong tplt lab[i]
int Find(int u)
{
	if(lab[u] < 0)	return u;
	lab[u] = Find(lab[u]);
	return lab[u];
}
ll join(int u , int v)
{
	u = Find(u) , v = Find(v);
	if(u == v)	return 0;
	if(lab[u] > lab[v])	swap(u , v);
	ll res = 1LL * lab[u] * lab[v];
	lab[u] += lab[v];
	lab[v] = u;
	return res;
}
ll get_value(int div)
{
	int num = 0;
	lab.clear();
	for (int i=div ; i<MAX_VALUE ; i+=div)
	{
		for (int x : indices[i])
		{
			int u = edges[x].fi;
			int v = edges[x].se;
			if(nodeId[u] < 0)	nodeId[u] = ++num;
			if(nodeId[v] < 0)	nodeId[v] = ++num;
		}
	}
	if(num == 0)	return 0;	
	ll res = 0;
	lab.assign(num + 1 , -1);
	for (int i=div ; i<MAX_VALUE ; i+=div)
	{
		for (int x : indices[i])
		{
			int u = edges[x].fi;
			int v = edges[x].se;
			res += join(nodeId[u] , nodeId[v]);
		}
	}
	for (int i=div ; i<MAX_VALUE ; i+=div)
	{
		for (int x : indices[i])
		{
			int u = edges[x].fi;
			int v = edges[x].se;
			nodeId[u] = nodeId[v] = -1;
		}
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("gcdpath.inp" , "r" , stdin);
    // freopen("gcdpath.out" , "w" , stdout);
    cin >> subtask >> n;
    for (int i=1 ; i<=n ; i++)	
    {
    	cin >> a[i];
    }
    for (int i=1 ; i<=n-1 ; i++)
    {
    	int u , v;
    	cin >> u >> v;
    	edges[i] = {u , v};
    	indices[__gcd(a[u] , a[v])].push_back(i);
    }
    memset(nodeId , -1 , sizeof(nodeId));
    cnt[1] = 1LL * n * (n - 1) / 2; 
    for (int i=2 ; i<MAX_VALUE ; i++)
    {
    	cnt[i] = get_value(i);
    	// cout << cnt[i] << endl;
    }
    for (int i=MAX_VALUE-1 ; i>=1 ; i--)
    {
    	for (int j=2*i ; j<MAX_VALUE ; j+=i)
    	{
    		cnt[i] -= cnt[j];
    	}
    }
    ll res = 0;
    for (int i=1 ; i<MAX_VALUE ; i++)
    {
    	// cout << cnt[i] << endl;
    	res += cnt[i] * i;
    }
    cout << res;
    return 0;
}