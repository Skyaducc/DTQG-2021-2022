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
#define ll long long
using namespace std;
const ll oo = 1e18;
const int MAXN = 5e5 + 1;
int subtask , n , q;
pii res[MAXN] , a[MAXN];
struct Info
{
	ll sum = 0;
	pair<ll , int> prefix , suffix;
	pair<ll , pii> bestsegment;
	Info()
	{
		sum = 0;
	}
	Info(int pos , ll value)
	{
		sum = value;
		prefix = suffix = {value , pos};
		bestsegment = {value , {pos , pos}};
	}
};
Info combine(const Info &x , const Info &y)
{
	Info res;
	res.sum = max(-oo , x.sum + y.sum);
	res.prefix = max(x.prefix , {x.sum + y.prefix.fi , y.prefix.se});
	res.suffix = max(y.suffix , {y.sum + x.suffix.fi , x.suffix.se});
	res.bestsegment = max(x.bestsegment , y.bestsegment);
	if(res.bestsegment.fi < x.suffix.fi + y.prefix.fi)
	{
		res.bestsegment = {x.suffix.fi + y.prefix.fi , {x.suffix.se , y.prefix.se}};
	}
	return res;
}
struct segmentTree
{
	vector<Info> tree;
	int n;
	segmentTree(int _n = 0)
	{
		n = _n;
		tree.assign(4 * n , Info());
	}
	void build(int id , int l , int r)
	{
		if(l == r)
		{
			tree[id] = Info(r , -oo);
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		tree[id] = combine(tree[id * 2] , tree[id * 2 + 1]);
	}
	void update(int id , int l , int r , int u , int v , int x)
	{
		if(r < u || v < l)	return;
		if(u <= l && r <= v)
		{
			tree[id] = {u , x};
			return;
		}
		int mid = (l + r) / 2;
		update(id * 2 , l , mid , u , v , x);
		update(id * 2 + 1 , mid + 1 , r , u , v , x);
		tree[id] = combine(tree[id * 2] , tree[id * 2 + 1]);
	}
	Info Get_max(int id , int l , int r , int u , int v)
	{
		if(r < u || v < l)	return Info(0 , -oo);
		if(u <= l && r <= v)
		{
			return tree[id];
		}
		int mid = (l + r) / 2;
		Info trai = Get_max(id * 2 , l , mid , u , v);
		Info phai = Get_max(id * 2 + 1 , mid + 1 , r , u , v);
		return combine(trai , phai);
	}
};
struct Data
{
	int l , r , b , id;
	Data(int _l = 0 , int _r = 0 , int _b = 0 , int _id = 0)
	{
		l = _l ; r = _r ; b = _b ; id = _id;
	}
	bool operator < (const Data &tmp)	const
	{
		return b > tmp.b;
	}
} query[MAXN];
void input()
{
	cin >> subtask >> n >> q;
    foru (i , 1 , n)
    {
    	cin >> a[i].fi;
    	a[i].se = i;
    }
    foru (i , 1 , q)
    {
    	int l , r , b;
    	cin >> l >> r >> b;
    	query[i] = {l , r , b , i};
    }
}
void solve()
{
	sort(a + 1 , a + 1 + n , greater<pii>());
	sort(query + 1 , query + 1 + q);
	segmentTree IT(n);
	IT.build(1 , 1 , n);
	int j = 1;
	foru (i , 1 , q)
	{
		int l = query[i].l , r = query[i].r , b = query[i].b;
		while(j <= n && a[j].fi >= b)
		{
			IT.update(1 , 1 , n , a[j].se , a[j].se , a[j].fi);
			j++;
		}
		Info tmp = IT.Get_max(1 , 1 , n , l , r);
		if(tmp.bestsegment.fi > -oo)	res[query[i].id] = tmp.bestsegment.se;
		else res[query[i].id] = {0 , 0};	
	}
	foru (i , 1 , q)
	{
		if(res[i].fi)
		{
			cout << res[i].fi << " " << res[i].se << endl;
		}
		else	cout << 0 << endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("maxsum.inp" , "r" , stdin);
    freopen("maxsum.out" , "w" , stdout);
    input();
    solve();
    return 0;
}
