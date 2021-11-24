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
const int MAXN = 1e5 + 11;
const int LOGN = 21;
int test , n , k;
vector<int> adj[MAXN];
int par[MAXN][LOGN + 1] , h[MAXN];
int num , a[MAXN] , t[MAXN];
int FAI[MAXN] , minNode[MAXN * 2][LOGN + 1] , sz = 0;
int timeIn[MAXN] , timeOut[MAXN];
#define MIN_HEIGHT(x , y) (h[x] < h[y] ? (x) : (y))
void init(int u , int par)
{
	timeIn[u] = ++num;
	FAI[u] = ++sz;
	minNode[sz][0] = u;
	for(int i=0 ; i<(int)adj[u].size() ; ++i)
	{
		int v = adj[u][i];
		if(v == par) continue;
		h[v] = h[u] + 1;
		init(v , u);
		minNode[++sz][0] = u;
	}
	timeOut[u] = num;
}
bool cmp(int x, int y)
{
	return timeIn[x] < timeIn[y];
}
int lca(int u , int v)
{
	int l = FAI[u] , r = FAI[v];
	if(l > r) swap(l , r);
	int k = log2(r - l + 1);
	return MIN_HEIGHT(minNode[l][k] , minNode[r-MASK(k)+1][k]);
}

void solve()
{
	cin >> k;
	foru (i , 1 , k)	cin >> t[i];
	sort(t + 1 , t + 1 + k , cmp);
	stack<int> st;
	st.push(t[1]);
	vector<int> v;
	v.push_back(t[1]);
	foru (i , 2 , k)
	{
		int u = lca(st.top() , t[i]);
		v.push_back(u);
		while(st.size())
		{
			int x = st.top();
			if(lca(u , x) == u)	st.pop();
			else break;
		}
		st.push(u);
		st.push(t[i]);
	}
	int res = oo;
	for (int u : v)
	{
		int sum = 0;
		foru (i , 1 , k)
		{
			int x = lca(u , t[i]);
			sum += h[u] + h[t[i]] - 2 * h[x];
		}
		res = min(res , sum);
	}
	cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    h[1] = 1;
	init(1 , -1);
	for(int j=1 ; MASK(j) <= sz ; ++j) for(int i=1 ; i+MASK(j)-1 <= sz ; ++i)
	{
		minNode[i][j] = MIN_HEIGHT(minNode[i][j-1] , minNode[i+MASK(j-1)][j-1]);
	}
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}