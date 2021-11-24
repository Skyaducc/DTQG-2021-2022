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
#define int long long
using namespace std;
const int oo = 1e18;
const int MAXN = 3e5 + 1;
int n;
int a[MAXN] , res[MAXN];
struct Info
{
	int val , lazy;
	Info(int _val = 0 , int _lazy = 0)
	{
		val = _val , lazy = _lazy;
	}
};
struct segmentTree
{
	int n;
	vector<Info> tree;
	segmentTree(int _n = 0)
	{
		n = _n;
		tree.assign(4 * n + 7 , 0);
	} 
	void push(int id)
	{
		int t = tree[id].lazy;
		tree[id * 2].val += t;
		tree[id * 2 + 1].val += t;
		tree[id * 2].lazy += t;
		tree[id * 2 + 1].lazy += t;
		tree[id].lazy = 0;
	}
	void build(int id , int l , int r)
	{
		if(l == r)
		{
			tree[id].val = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		tree[id].val = min(tree[id * 2].val , tree[id * 2 + 1].val);
	}
	void update(int id , int l , int r , int u , int v , int x)
	{
		if(r < u || v < l)	return;
		if(u <= l && r <= v)
		{
			tree[id].val += x;
			tree[id].lazy += x;
			return;
		}
		int mid = (l + r) / 2;
		push(id);
		update(id * 2 , l , mid , u , v , x);
		update(id * 2 + 1 , mid + 1 , r , u , v , x);
		tree[id].val = min(tree[id * 2].val , tree[id * 2 + 1].val);
	}
	int get_pos(int id , int l , int r)
	{
		if(l == r)	return l;
		int mid = (l + r) / 2;
		push(id);
		if(tree[id * 2 + 1].val == 0)
		{
			return get_pos(id * 2 + 1 , mid + 1 , r);
		}	
		else
		{
			return get_pos(id * 2 , l , mid);
		}
		return 0;
	}
};
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i];
    segmentTree IT(n);
    IT.build(1 , 1 , n);
    int tmp = 0;
    foru (i , 1 , n)
    {
    	int pos = IT.get_pos(1 , 1 , n);
    	// cout << pos << endl;
    	res[pos] = ++tmp;
    	IT.update(1 , 1 , n , pos + 1 , n , -tmp);
    	IT.update(1 , 1 , n , pos , pos , oo);
    }
    foru (i , 1 , n)	cout << res[i] << " ";
    return 0;
}
