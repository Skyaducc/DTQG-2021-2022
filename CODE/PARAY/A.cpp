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
const int oo = 1e9;
const int MAXN = 2e5 + 11;
int NumBlock;
int n , m , res;
int a[MAXN] , ans[MAXN];
int cnt[1000011];
struct Query
{
	int l , r , id;
	bool operator < (const Query &tmp)	const
	{
		if(l / NumBlock == tmp.l / NumBlock)	return r < tmp.r;
		else return l < tmp.l;
	}
} q[MAXN];
void add(int x)
{
	res -= cnt[a[x]] * cnt[a[x]] * a[x];
	cnt[a[x]]++;
	res += cnt[a[x]] * cnt[a[x]] * a[x];
}
void del(int x)
{
	res -= cnt[a[x]] * cnt[a[x]] * a[x];
	cnt[a[x]]--;
	res += cnt[a[x]] * cnt[a[x]] * a[x];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , m)
    {
    	int l , r;
    	cin >> l >> r;
    	q[i] = {l , r , i};
    }
    NumBlock = sqrt(n);
    sort(q + 1 , q + 1 + m);
    int l = 1 , r = 0;
    foru (i , 1 , m)
	{
		while (l < q[i].l) del(l++);
		while (l > q[i].l) add(--l);
		while (r < q[i].r) add(++r);
		while (r > q[i].r) del(r--);
		ans[q[i].id] = res;
	}
    foru (i , 1 , m)	cout << ans[i] << endl;
    return 0;
}