// cạnh (i , j) được nối nếu gcd(a[i] , a[j]) > k
// với mỗi ước k từ k + 1 -> 1e7 nối các cạnh a[i] chia hết cho k
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
const int MAXN = 1e6 + 1;
const int MAX = 1e7 + 1;
int n , k , q;
int a[MAXN];
vector<int> num[10000006];
int mark[MAX];
int root[MAXN]; 
int get_root(int u)
{
	if(root[u] == 0)	return u;
	root[u] = get_root(root[u]);
	return root[u];
}
void join(int u , int v)
{
	u = get_root(u) , v = get_root(v);
	if(u != v)	root[u] = v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("gcd-graph.inp" , "r" , stdin);
    freopen("gcd-graph.out" , "w" , stdout);
    cin >> n >> k >> q;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	num[a[i]].push_back(i);
    }
    for (int i=k+1 ; i<MAX ; i++)
    {
    	int u = 0;
    	if(mark[i])	continue;
    	for (int j=i ; j<MAX ; j+=i)
    	{
    		for (int v : num[j])
    		{
    			if(!u)	u = v;
    			else	join(u , v);
    		}
    		mark[j] = 1;
    	}
    }
    while(q--)
    {
    	int u , v;
    	cin >> u >> v;
    	u = get_root(u) , v = get_root(v);
    	if(u == v)	cout << "Y";
    	else	cout << "N";
    }
    return 0;
}
