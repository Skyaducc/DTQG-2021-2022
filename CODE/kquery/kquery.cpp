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
using namespace std;
const int MAXN = 30001;
const int oo = 1e9 + 1;
int n , q;
int a[MAXN];
int tree[500001];
int ans;
void build(int id , int l, int r)
{
	if(l == r)
	{
		tree[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	tree[id] = min(tree[id*2] , tree[id*2+1]);
}
void Get(int id , int l , int r , int u , int v , int val)
{
	if(r < u || v < l)
	{
		return;
	}
	if(u <= l && r <= v)
	{
		if(tree[id] > val)
		{
			// cout << id << " " << l << " " << r << " " << tree[id] << endl;
			if(tree[id] < oo)	ans += r - l + 1;
			return;
		}
	}	
	int mid = (l + r) / 2;
	Get(id * 2 , l , mid , u , v , val);
	Get(id * 2 + 1 , mid + 1 , r , u , v , val);
}
void solve()
{
	int i , j , k;
	cin >> i >> j >> k;
	Get(1 , 1 , n , i , j , k);
	cout << ans << endl;
	ans = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    memset(tree , 0x3f , sizeof(tree));
    cin >> n;
    for (int i=1 ; i<=n ; i++)	cin >> a[i];
   	build(1 , 1 , n);
    cin >> q;
    while(q--)
    {
    	solve();
    }
    return 0;
}
